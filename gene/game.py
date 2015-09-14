from evoinit import *

AI_KickAura = 8

class Counter:
    def __init__(self):
        self.RP = 0
        self.BP = 0

class Ball:
    
    def __init__(self, x, y):
        self.x_spd = 0
        self.y_spd = 0
        self.x = x
        self.y = y

    def rolf(self, tick):
        self.x += self.x_spd * tick
        self.y += self.y_spd * tick
        if(self.x > MapWidth):
            self.x = MapWidth
            self.x_spd *= -1
        elif(self.x < 0):
            self.x = 0
            self.x_spd *= -1
        if(self.y > MapHeight):
            self.y = MapHeight
            self.y_spd *= -1
        elif(self.y < 0):
            self.y = 0
            self.y_spd *= -1

        if(abs(self.x_spd) > 0.999):
            self.x_spd *= 0.99
        else:
            self.x_spd = 0

        if(abs(self.y_spd) > 0.999):
            self.y_spd *= 0.99
        else:
            self.y_spd = 0
            
    def bl(self):
        screen.blit(ball, (self.x, self.y))
    def bl(self, x, y):
        screen.blit(ball, (x, y))

    def reset(self):
        self.x = MapWidth / 2
        self.y = MapHeight / 2
        self.x_spd = 0
        self.y_spd = 0

    def goal(self, c):
        if(self.y >= Goal_TBorder and self.y <= Goal_DBorder):
            if(self.x <= LGoal_xBorder):
                c.RP += 1
                print 'goal!'
                return 59
            if(self.x >= RGoal_xBorder):
                c.BP += 1
                return 60

def kick(p, b, f, s):
    if(b.x + bimg_width >= p.x and b.x + bimg_width/2 <= p.x + bpimg_width and
       b.y + bimg_height/2 >= p.y and b.y + bimg_height/2 <= p.y + bpimg_height):
        if 'i' in f:
            b.y_spd -= 7 * p.str
        if 'j' in f:
            b.x_spd -= 7 * p.str
        if 'k' in f:
            b.y_spd += 7 * p.str
        if 'l' in f:
            b.x_spd += 7 * p.str
        s.counter = 0
        
            
class roller:
    def __init__(self):
        self.lx = 0
        self.ly = 0
        
    def update(self, p):
        self.lx = -p.x + ScreenWidth / 2
        self.ly = -p.y + ScreenHeight / 2

class Camera:

    def __init__(self, x, y):
        self.x = x
        self.y = y
        self.sx = ScreenWidth / 2
        self.sy = ScreenHeight / 2

    def move(self, d, spd, R):
        self.f = []
        self.tx = self.x
        self.ty = self.y
        if 'w' in d:
            self.y -= spd * 400
        if 'a' in d:
            self.x -= spd * 400
        if 's' in d:
            self.y += spd * 400
        if 'd' in d:
            self.x += spd * 400

        if(self.x >= MapWidth):
            self.x = MapWidth
        if(self.y >= MapHeight):
            self.y = MapHeight
        if(self.x <= 0):
            self.x = 0
        if(self.y <= 0):
            self.y = 0

        R.update(self)

class Player:

    def __init__(self, x, y, t):
        self.x = x
        self.y = y
        self.str = random.randint(10, 30)
        self.dex = int((150 - self.str) / 2)
        self.team = t

    def reset(self, x, y):
        self.x = x
        self.y = y

    def genemove(self, spd, soccer, swag):
        tag = []
        ttag = []
        if(swag.outcell[0] > 0):
            tag.append('w')
            self.y -= 400 * spd
        if(swag.outcell[1] > 0):
            tag.append('a')
            self.x -= 400 * spd
        if(swag.outcell[2] > 0):
            tag.append('s')
            self.y += 400 * spd
        if(swag.outcell[3] > 0):
            tag.append('d')
            self.x += 400 * spd
        if (self.x > MapWidth):
            self.x = MapWidth
            return 400
        if (self.y > MapHeight):
            self.y = MapHeight
            return 400
        if (self.x < 0):
            self.x = 0
            return 400
        if (self.y < 0):
            self.y = 0
            return 400
        k = []
        if(swag.outcell[4] > 0):
            k.append('i')
            ttag.append('i')
        if(swag.outcell[5] > 0):
            k.append('j')
            ttag.append('j')
        if(swag.outcell[6] > 0):
            k.append('k')
            ttag.append('k')
        if(swag.outcell[7] > 0):
            k.append('l')
            ttag.append('l')
        if(swag.counter >= 400):
            return 401
        #print tag
        kick(self, soccer, k, swag)
        return 0
        
    def bl(self, x, y, img):
        screen.blit(img, (x, y))
