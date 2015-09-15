from game import *
from train import *

RandomPlayer = True

def main():

    counter = Counter()

    R = roller()

    soccer = Ball(MapWidth / 2, MapHeight / 2)

    if(RandomPlayer):
        p = Player(1024, random.randint(0, MapHeight), 'R')
    else:
        p = Player(1024, MapHeight/2, 'R')

    s = []

    t = []

    for i in range(0, 6):
        s.append(Swag(0, 0, 0))

    #mc = Camera(0, 0)

    move_ticker = 0

    font = pygame.font.Font('FerroRosso.ttf', 32)

    #MID_X = mc.sx - bpimg_height/2
    #MID_Y = mc.sy - bpimg_width/2

    clock = pygame.time.Clock()

    frame_clock = pygame.time.Clock()

    view = 1

    now = 0

    rd = 0

    maxrd = 100

    print 'Round: 0'

    while True and rd <= maxrd:

        time_passed = clock.tick()

        spd = time_passed / 1000.0

        soccer.rolf(spd)

        keys = pygame.key.get_pressed()

        k = []

        if keys[pygame.K_w]:
            k.append('w')
        if keys[pygame.K_a]:
            k.append('a')
        if keys[pygame.K_s]:
            k.append('s')
        if keys[pygame.K_d]:
            k.append('d')

        if keys[pygame.K_i]:
            k.append('i')
        if keys[pygame.K_j]:
            k.append('j')
        if keys[pygame.K_k]:
            k.append('k')
        if keys[pygame.K_l]:
            k.append('l')

        #mc.move(k, spd, R)
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                view *= -1

        #screen.blit(bla, (0, 0))

        #screen.blit(bg, (R.lx, R.ly))
        screen.blit(bg, (0, 0))

        s[now].comp(p, soccer)
        num = p.genemove(spd, soccer, s[now])
        go = soccer.goal(counter)
        if(go == 59):
            s[now].rival -= 50
        elif(go ==60):
            s[now].rival += 50
        if(num >= 400):
            if(num == 400):
                print s[now].rival, 'out of border'
            elif(num == 401):
                print s[now].rival, 'stun'
            now += 1
            if(RandomPlayer):
                p.reset(1024, random.randint(0, MapHeight))
            else:
                p.reset(1024, MapHeight/2)
            soccer.reset()
        if(now >= len(s)):
            print
            print '---prepare next gene---'
            AISort(s, len(s))
            AICopy(s, t, len(s))
            AICrossover(s, len(s), t, 10)
            AIMutate(t, len(s), 90)
            s = t
            for ai in s:
                ai.rival = 9999
            #s[len(s)-1].reset()
            rd += 1
            now = 0
            t = []
            if(RandomPlayer):
                p.reset(1024, random.randint(0, MapHeight))
            else:
                p.reset(1024, MapHeight/2)
            soccer.reset()
            print '-----------------------'
            print
            print 'Round:', rd
        '''if(abs(p.x - mc.x) <= ScreenWidth / 2 and abs(p.y - mc.y) <= ScreenHeight / 2):
            if(p.team == 'R'):
                p.bl(p.x + R.lx - rpimg_height / 2, p.y + R.ly - rpimg_width / 2, rplayer)
            else:
                p.bl(p.x + R.lx - rpimg_height / 2, p.y + R.ly - rpimg_width / 2, bplayer)'''
        p.bl(p.x - rpimg_height / 2, p.y - rpimg_width / 2, bplayer)
        '''if(view < 0):
            mc.x = p.x
            mc.y = p.y'''

        soccer.bl(soccer.x - bimg_height, soccer.y - bimg_width)

        '''if(abs(soccer.x - mc.x) <= ScreenWidth / 2 and abs(soccer.y - mc.y) <= ScreenHeight / 2):
            soccer.bl(soccer.x + R.lx - bimg_height / 2, soccer.y + R.ly - bimg_width / 2)'''
            
        text = font.render("FPS:%d" % clock.get_fps(), 1, (0, 0, 255))
        point = font.render("%d:%d" % (counter.BP, counter.RP), 1, (0, 0, 255))

        screen.blit(point, (0, ScreenHeight - 30))
        screen.blit(text, (0, 0))

        pygame.display.update()

        frame_clock.tick(60)

if __name__ == '__main__':
    main()
    pygame.quit()
    exit()
