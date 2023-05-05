import pygame
import os
import time
import random
import math
import json
from operator import itemgetter
from pygame import mixer

pygame.init()

## setDelta ##

deltaY = 18.75

## setFont

white = (255,255,255)
black = (0,0,0)
green = (0,255,0)
red = (255,0,0)

## setDisplay-Background ##

width , height = 750, 600
icon = pygame.image.load(os.path.join("image","BR.png"))
pygame.display.set_icon(icon)
backgroundSize = pygame.display.set_mode((width,height))
pygame.display.set_caption("SPACE X")

## setRocket ##

redRocketImg = pygame.image.load(os.path.join("image","RR.png"))
redRocket = pygame.transform.scale(redRocketImg,(45,45))

greenRocketImg = pygame.image.load(os.path.join("image","GR.png"))
greenRocket = pygame.transform.scale(greenRocketImg,(45,45))

violetRocketImg = pygame.image.load(os.path.join("image","VR.png"))
violetRocket = pygame.transform.scale(violetRocketImg,(45,45))

blueRocketImg = pygame.image.load(os.path.join("image","BR.png"))
player = pygame.transform.scale(blueRocketImg ,(90,90))

## setBullet ##

redBulletImg = pygame.image.load(os.path.join("image","RB.png"))
redBullet = pygame.transform.scale(redBulletImg,(30,7.5))

greenBulletImg = pygame.image.load(os.path.join("image","GB.png"))
greenBullet = pygame.transform.scale(greenBulletImg,(30,7.5))

violetBulletImg = pygame.image.load(os.path.join("image","VB.png"))
violetBullet = pygame.transform.scale(violetBulletImg,(30,7.5))

playerBulletImg = pygame.image.load(os.path.join("image","BB.png"))
playerBullet = pygame.transform.scale(playerBulletImg,(37.5,52.5))

## background ##

backgroundImg = pygame.image.load(os.path.join("image","mainBG.png"))
background = pygame.transform.scale(backgroundImg,(width,height))

## setClass ##

class Bullet :

    def __init__(self, x, y, img):
        self.x = x
        self.y = y
        self.img = img
        self.mask = pygame.mask.from_surface(self.img)

    def draw(self,window):

        window.blit(self.img, (self.x,self.y+deltaY))

    def movement(self,vel):

        self.x += vel

    def outScreen(self,width) :

        return (self.x >= 0 and self.x < width)

    def collision(self,obj):

        return coli(self,obj) 

class Rocket:

    COOLDOWN = 55
 
    def __init__(self, x, y, health=100):
        self.x = x
        self.y = y
        self.health = health
        self.rocketImg = None
        self.bulletImg = None
        self.bullets = []
        self.CD = 0

    def draw(self, window) :
        window.blit(self.rocketImg,(self.x,self.y))

        for bullet in self.bullets:
            bullet.draw(backgroundSize)

    def moveBullet(self,vel,obj):

        self.cooldown()

        for bullet in self.bullets:

            bullet.movement(vel)

            if bullet.outScreen(0):

                self.bullets.remove(bullet)

            elif bullet.collision(obj):

                hpS = mixer.Sound('music/coli.wav')
                hpS.play()

                if (level >= 1 and level <= 7) :

                    obj.health -= 10

                elif (level >= 8 and level <= 15):

                    obj.health -= 15

                elif (level >= 16 and level <= 30):

                    obj.health -= 30

                else :

                    global lives
                    lives -= 1

                self.bullets.remove(bullet)

    def cooldown(self):

        if self.CD >= self.COOLDOWN :

            self.CD = 0

        elif self.CD > 0:

            self.CD  += 1

    def shoot(self):

        if self.CD == 0:

            bullet = Bullet(self.x, self.y, self.bulletImg)

            self.bullets.append(bullet)

            shootS = mixer.Sound('music/laser.wav')
            shootS.play()

            self.CD  = 1

    def get_width(self):
        return self.rocketImg.get_width()

    def get_height(self):
        return self.rocketImg.get_height()

class Player(Rocket):

    def __init__(self, x, y, health=100):

        super().__init__(x, y, health)
        self.rocketImg = player
        self.bulletImg = playerBullet
        self.mask = pygame.mask.from_surface(self.rocketImg)
        self.maxHealth = health

    def moveBullet(self,vel,objs):

        self.cooldown()

        for bullet in self.bullets:
            bullet.movement(vel)

            if bullet.outScreen(0):
                self.bullets.remove(bullet)

            else:

                for obj in objs :

                    if bullet.collision(obj):
                        objs.remove(obj)

                        if bullet in self.bullets:
                            self.bullets.remove(bullet)

    def draw(self,window):

        super().draw(window)

        self.untimate(window)

    def untimate(self,window):

        pygame.draw.rect(window,red,(25,10,690,15))
        pygame.draw.rect(window,green,(25,10,690*(self.health/100),15))

class Enermy(Rocket):
    COLOR_BASE ={
                "red" : (redRocket,redBullet),
                "green" : (greenRocket,greenBullet),
                "violet" : (violetRocket,violetBullet)
                }

    def __init__(self, x, y,color,health = 100):

        super().__init__(x,y,health)
        self.rocketImg,self.bulletImg = self.COLOR_BASE[color]
        self.mask = pygame.mask.from_surface(self.rocketImg)

    def movement(self, vel) :
        self.x -= vel

    def shoot(self):

        if self.CD == 0:

            bullet = Bullet(self.x, self.y, self.bulletImg)

            self.bullets.append(bullet)

            self.CD  = 1

def coli(obj1,obj2):

    distanceX = (obj2.x - obj1.x)
    distanceY = (obj2.y - obj1.y)-deltaY

    return obj1.mask.overlap(obj2.mask, (distanceX, distanceY)) != None

def textObject(text,font):

    textSurface = font.render(text,True,white)
    return textSurface , textSurface.get_rect()

def paused ():

    pygame.mixer.music.pause()
    font = pygame.font.Font('gameFont.ttf',30)
    largeText = pygame.font.Font('gameFont.ttf',80)
    TextSurf,TextRect = textObject('PAUSED',largeText)
    TextRect.center = (400,300)
    backgroundSize.blit(TextSurf,TextRect)

    while pause :

        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                quit()

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_u:
                    unpause()

        pygame.display.update()

def unpause ():

    global pause
    pygame.mixer.music.unpause()
    pause = False

def button(msg,x,y,w,h,ic,ac,action=None):

    mouse = pygame.mouse.get_pos()
    click = pygame.mouse.get_pressed()

    if x+w > mouse[0] > x and y+h > mouse[1] > y:

        pygame.draw.rect(backgroundSize,ac,(x,y,w,h))

        if click[0] == 1 and action != None:

            action()

    else:
        pygame.draw.rect(backgroundSize,ac,(x,y,w,h))

    fontGame = pygame.font.Font('gameFont.ttf',35)
    TextSurf,TextRect = textObject(msg,fontGame)
    TextRect.center = ((x+w/2),(y+h/2))
    backgroundSize.blit(TextSurf,TextRect)

def quitGame():

    pygame.quit()
    quit()

def score():

    with open('score.json','r') as file:
        level = json.load(file)

    start = True

    while start:

        backgroundSize.blit(background,(0,0))
        fontGame1 = pygame.font.Font('gameFont.ttf',50)
        startText = fontGame1.render('<Leaderboard>',True,white)
        backgroundSize.blit(startText,(180,20))

        fontGame2 = pygame.font.Font('gameFont.ttf',35)
        nameT = fontGame2.render('<NAME>',True,white)
        backgroundSize.blit(nameT,(100,120))
        levelT = fontGame2.render('<LEVEL>',True,white)
        backgroundSize.blit(levelT,(500,120))

        fontGame = pygame.font.Font('gameFont.ttf',35)


        for i,data in enumerate(level):

            startText = fontGame.render(data[0],True,white)
            backgroundSize.blit(startText,(100,180+(i*60)))

            startText = fontGame.render(str(data[1]),True,white)
            backgroundSize.blit(startText,(500,180+(i*60)))

        ## setButton
        button("<-- BACK",50,520,150,40,green,black,mainManu)
        # button("START GAME -->",450,520,250,40,green,green,main)

        pygame.display.update()

        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                quitGame()

    pygame.quit()

def updatescore(playerlevel):

    isCooldown = False
    startDel = 0
    coolDownTime = 0.08
    name = ""


    with open('score.json','r') as file:
        level = json.load(file)

    start = True

    while start:

        backgroundSize.blit(background,(0,0))
        fontGame = pygame.font.Font('gameFont.ttf',50)
        startText = fontGame.render('YOUR SCORE : '+str(playerlevel),True,white)
        text_rect = startText.get_rect(center=(width/2, 60))
        backgroundSize.blit(startText, text_rect)

        fontGame1 = pygame.font.Font('gameFont.ttf',40)
        startText1 = fontGame1.render(' PLEASE ENTER YOUR NAME ',True,white)
        text_rect = startText1.get_rect(center=(width/2, 160))
        backgroundSize.blit(startText1, text_rect)

        startText1 = fontGame1.render('__________________________',True,white)
        text_rect = startText1.get_rect(center=(width/2, height/2-50))
        backgroundSize.blit(startText1, text_rect)

        startText1 = fontGame1.render('|                         |',True,white)
        text_rect = startText1.get_rect(center=(width/2, height/2))
        backgroundSize.blit(startText1, text_rect)

        startText1 = fontGame1.render('|                         |',True,white)
        text_rect = startText1.get_rect(center=(width/2, height/2+30))
        backgroundSize.blit(startText1, text_rect)

        startText1 = fontGame1.render('__________________________',True,white)
        text_rect = startText1.get_rect(center=(width/2, height/2+50))
        backgroundSize.blit(startText1, text_rect)

        startText1 = fontGame1.render('PRESS ENTER TO MAINMENU',True,white)
        text_rect = startText1.get_rect(center=(width/2, height/2+200))
        backgroundSize.blit(startText1, text_rect)

        text = fontGame.render(name, True, white)
        text_rect = text.get_rect(center=(width/2, height/2+10))
        backgroundSize.blit(text, text_rect)

        pygame.display.update()

        for event in pygame.event.get():

            if event.type == pygame.KEYDOWN:
                if event.key == pygame.K_RETURN:
                    if name.replace(" ","") == "":
                        name = "Unknown"

                    with open('score.json', 'r') as file:
                        level = json.load(file)

                    level.append([name,int(playerlevel)])
                    level = sorted(level,reverse = True, key=itemgetter(1))
                    if len(level) > 5:
                        level.pop()

                    with open('score.json', 'w+') as file:
                        json.dump(level,file)
                    return 

                elif not event.key == pygame.K_BACKSPACE:
                    name += event.unicode

            if event.type == pygame.QUIT:
                    quitGame()
        
        if pygame.key.get_pressed()[pygame.K_BACKSPACE] and not isCooldown:
            
            isCooldown = True
            startDel = pygame.time.get_ticks()
            if len(name) <= 1:
                name = ""
            else:
                name = name[:-1]

        if len(name) > 15:
            name = name[:15]

        if (pygame.time.get_ticks() - startDel)/1000 >= coolDownTime and isCooldown:
            isCooldown = False

    pygame.quit()

def tutorial():

    start = True

    while start:

        backgroundSize.blit(background,(0,0))
        fontGame1 = pygame.font.Font('gameFont.ttf',50)
        startText = fontGame1.render('<TUTORIAL>',True,white)
        backgroundSize.blit(startText,(180,20))

        tutorialImg = pygame.image.load(os.path.join("image","tutorial.png"))
        tutorial = pygame.transform.scale(tutorialImg,(width,height))
        backgroundSize.blit(tutorial,(0,0))

    

        ## setButton
        button("<-- BACK",60,550,150,40,green,black,mainManu)
        # button("START GAME -->",450,520,250,40,green,green,main)

        pygame.display.update()

        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                quitGame()

    pygame.quit()


def main():

    global pause
    global lives
    global level

    ## setGame ##
    start = True
    FPS = 120
    level = 0
    lives = 2
    fontGame = pygame.font.Font('gameFont.ttf',30)
    time = pygame.time.Clock()

    ## setPlayer ##
    player = Player(0,320)
    playerSpeed = 3
    bulletSpeed = 6 

    ## setEnermy ##
    enermySpeed = 1
    waveLength1 = 5
    waveLength2 = 7
    waveLength3 = 10
    enermies = []

    recovery= False
    recoveryCount = 0

    alives= False
    alivesCount = 0

    blives= False
    blivesCount = 0

    def updateDis():

        ## updateBackground ##
        backgroundSize.blit(background,(0,0))

        ## text ##
        levelText = fontGame.render('LEVEL : '+ str(level),True,white)
        backgroundSize.blit(levelText,(25,15))
        livesText = fontGame.render('LIVES : '+ str(lives),True,white)
        backgroundSize.blit(livesText,(550,15))

        ## updateEnermy ##
        for enermy in enermies:
            enermy.draw(backgroundSize)

        if lives <= 1 and level != 1:
            dText = fontGame.render(' DANGER ',True,red)
            backgroundSize.blit(dText,(550,50))

        if (level >= 1 and level <= 7) : 
            state1 = fontGame.render('DAMAGE : NORMAL ',True,white)
            backgroundSize.blit(state1,(25,50))

        elif (level >= 8 and level <= 15) : 
            state2 = fontGame.render('DAMAGE : 150 % ',True,white)
            backgroundSize.blit(state2,(25,50))

        elif (level >= 16 and level <= 30) : 
            state3 = fontGame.render('DAMAGE : 300 % ',True,white)
            backgroundSize.blit(state3,(25,50))

        else : 
            state4 = fontGame.render('ONE SHOT ONE LIVES ',True,white)
            backgroundSize.blit(state4,(25,50))


        ## textRecovery ##
        if recovery == True :

            recoveryText = fontGame.render('recovery 100 %',True,white)
            backgroundSize.blit(recoveryText,(width/2 - recoveryText.get_width()/2,height/2-50))

        if alives == True :

            alivesText = fontGame.render('LIVES + 1',True,white)
            backgroundSize.blit(alivesText,(width/2 - alivesText.get_width()/2,height/2))

        if blives == True :

            blivesText = fontGame.render('SPACIAL BONOUS : LIVES + 2',True,white)
            backgroundSize.blit(blivesText,(width/2 - blivesText.get_width()/2,height/2))

        ## updatePlayer ##
        player.draw(backgroundSize)
        pygame.display.update()

    while start == True :

        time.tick(FPS)
        updateDis()

        if player.health <= 0:
            player.health = 100
            lives = lives - 1

        if lives <= 0 :
            updatescore(level)
            return 

        if (level % 3 == 0 and level != 0 and level != 15 and level != 30 and level != 45 and level != 60 and level != 75 and level != 90 and level != 105)  :

                recovery = True
                recoveryCount += 1

                if recovery == True :

                    if recoveryCount > FPS * 3: ## delay 3 sec
                        recovery = False

                    else :
                        recovery = True
        else :

            recoveryCount = 0

        if (level % 5 == 0 and level != 0) :

                alives = True
                alivesCount += 1

                if alives == True :

                    if alivesCount > FPS * 3: ## delay 3 sec
                        alives = False

                    else :
                        alives = True
        else :

            alivesCount = 0

        if (level == 8 or level == 16 or level == 31) :

                blives = True
                blivesCount += 1

                if blives == True :

                    if blivesCount > FPS * 3: ## delay 3 sec
                        blives = False

                    else :
                        blives = True
        else :

            blivesCount = 0


        # if (level % 15 == 0 and level != 0) :

        #         alives = True
        #         alivesCount += 1

        #         if alives == True :

        #             if alivesCount > FPS * 3: ## delay 3 sec
        #                 alives = False

        #             else :
        #                 alives = True
        # else :

        #     alivesCount = 0

        if len(enermies) == 0 :

            level += 1

            if (level >= 1 and level <= 7) :

                if  (level) % 3 == 0 and level != 0:
                    player.health = 100
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 5 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 15 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                waveLength1 += 1

                for i in range(waveLength1):
                    enermy = Enermy(random.randrange(width,width+width/2),
                                        random.randrange(70,height-45),
                                        random.choice(["red","green","violet"]))
                    enermies.append(enermy)

            elif (level >= 8 and level <= 15) :

                if  (level) == 8 :
                    lives+=2
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                if  (level) % 3 == 0 and level != 0:
                    player.health = 100
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 5 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 15 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                waveLength2 += 1

                for i in range(waveLength2):
                    enermy = Enermy(random.randrange(width,width+width/2),
                                        random.randrange(70,height-45),
                                        random.choice(["red","green","violet"]))
                    enermies.append(enermy)

            elif (level >= 16 and level <= 30) :

                if  (level) == 16 :
                    lives+=2
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                if  (level) % 3 == 0 and level != 0:
                    player.health = 100
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 5 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 15 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                waveLength3 += 1

                for i in range(waveLength3):
                    enermy = Enermy(random.randrange(width,width+width/2),
                                        random.randrange(70,height-45),
                                        random.choice(["red","green","violet"]))
                    enermies.append(enermy)

            else :

                if  (level) == 31 :
                    lives+=2
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                if  (level) % 3 == 0 and level != 0:
                    player.health = 100
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 5 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                elif  (level) % 15 == 0 and level != 0:
                    lives += 1
                    rS = mixer.Sound('music/r.mp3')
                    rS.play()

                waveLength3 += 1

                for i in range(waveLength3):
                    enermy = Enermy(random.randrange(width,width+width/2),
                                        random.randrange(70,height-45),
                                        random.choice(["red","green","violet"]))
                    enermies.append(enermy)

        ## setKey ##
        for event in pygame.event.get() :

            if event.type == pygame.QUIT :
                quit()

        keys = pygame.key.get_pressed()

        if keys[pygame.K_s]:
            player.y += playerSpeed
            # print("s")

        if keys[pygame.K_w]:
            player.y -= playerSpeed
            # print("w")

        if keys[pygame.K_d]:
            player.x += playerSpeed
            # print("d")

        if keys[pygame.K_a]:
            player.x -= playerSpeed
            # print("a")

        if keys[pygame.K_p]:
            pause = True
            paused()

        if keys[pygame.K_q]:
            updatescore(level)
            return 
           

        if keys[pygame.K_SPACE]:
            player.shoot()

        ## border ##

        if player.y + playerSpeed + player.get_height() > height  :
            player.y = height - player.get_height()

        if player.y + playerSpeed < 70 :
            player.y = 70 

        if player.x + playerSpeed + player.get_width() > width  :
            player.x = width - player.get_width()

        if player.x + playerSpeed < 0  :
            player.x = 0

        for enermy in enermies[:]:

            enermy.movement(enermySpeed)
            enermy.moveBullet(-bulletSpeed/2 , player)

            if random.randrange(0,7*60) == 1:
                enermy.shoot()

            if coli(enermy,player):

                hpS = mixer.Sound('music/coli.wav')
                hpS.play()

                enermies.remove(enermy)

                if (level >= 1 and level <= 7) :

                    player.health -= 20

                elif (level >= 8 and level <= 15):

                    player.health -= 30

                elif (level >= 16 and level <= 30):

                    player.health -= 60

                else :

                    lives -= 1

            if enermy.x == 0 :

                enermies.remove(enermy)

                hpS = mixer.Sound('music/coli.wav')
                hpS.play()

                if (level >= 1 and level <= 7) :

                    player.health -= 30

                elif (level >= 8 and level <= 15):

                    player.health -= 45

                elif (level >= 16 and level <= 30):

                    player.health -= 90

                else :

                    lives -= 1

        player.moveBullet(bulletSpeed, enermies)

def mainManu():

    S = mixer.Sound("music/mainMu.mp3")
    S.play()

    start = True
    while start:

        backgroundSize.blit(background,(0,0))
        fontGame = pygame.font.Font('gameFont.ttf',60)
        startText = fontGame.render('SPACE X',True,white)
        fontGame = pygame.font.Font('gameFont.ttf',20)
        startText1 = fontGame.render('65010329 Nattawut Chayauam',True,white)
        backgroundSize.blit(startText,(250,50))
        backgroundSize.blit(startText1,(400,565))
        backgroundSize.blit(player,(150,60))
        backgroundSize.blit(player,(550,60))


        ## setButton
        button("START",300,250,200,50,green,black,main)
        button("TUTORIAL",300,320,200,50,green,black,tutorial)
        button("SCOREBOARD",300,390,200,50,green,black,score)
        button("QUIT",300,460,200,50,green,black,quitGame)

        # buttonStart("SCOREBOARD",300,350,200,50,green,red,main)
        # buttonQuit("QUIT",325,450,150,50,green,black,quitGame)

        pygame.display.update()

        for event in pygame.event.get():

            if event.type == pygame.QUIT:
                quitGame()

    pygame.quit()
    
mainManu()

