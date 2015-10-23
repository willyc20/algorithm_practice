from game import *
from train import *

RandomPlayer = False

Size = 6

def main():

    counter = Counter()

    R = roller()

    #soccer = Ball(MapWidth / 2, MapHeight / 2)

    p = []

    '''if(RandomPlayer):
        p = Player(1024, random.randint(0, MapHeight), 'R')
    else:
        p = Player(1024, MapHeight/3, 'R')'''

    s = []

    b = []

    t = []

    live = []

    for i in range(0, Size):
        s.append(Swag(0, 0, 0))
        b.append(Ball(MapWidth / 2, MapHeight / 2))
        p.append(Player(1024, MapHeight/3, 'R'))
        live.append(i)

    #mc = Camera(0, 0)

    move_ticker = 0

    font = pygame.font.Font('FerroRosso.ttf', 32)

    #MID_X = mc.sx - bpimg_height/2
    #MID_Y = mc.sy - bpimg_width/2

    clock = pygame.time.Clock()

    frame_clock = pygame.time.Clock()

    view = 1

    #now = 0

    rd = 0

    maxrd = 100

    print 'Round: 0'

    while True and rd <= maxrd:

        time_passed = clock.tick()

        spd = time_passed / 1000.0

        #soccer.rolf(spd)
        
        for event in pygame.event.get():
            if event.type == pygame.QUIT:
                pygame.quit()
                exit()
            if event.type == pygame.MOUSEBUTTONDOWN:
                view *= -1

        #screen.blit(bla, (0, 0))

        #screen.blit(bg, (R.lx, R.ly))
        screen.blit(bg, (0, 0))

        for now in range(0, Size):
            if now in live:

                b[now].rolf(spd)

                s[now].comp(p[now], b[now])
                num = p[now].genemove(spd, b[now], s[now])
                go = b[now].goal(counter)
                
                if(go == 59):
                    s[now].rival -= 50
                elif(go ==60):
                    s[now].rival += 50
                if now<len(bplis):
                    p[now].bl(p[now].x - rpimg_height / 2, p[now].y - rpimg_width / 2, bplis[now])
                else:
                    p[now].bl(p[now].x - rpimg_height / 2, p[now].y - rpimg_width / 2, bplayer)
                b[now].bl(b[now].x - bimg_height, b[now].y - bimg_width)
                
                if(num >= 400):
                    b[now].reset()
                    if(num == 400):
                        print s[now].rival, 'out of border'
                    elif(num == 401):
                        print s[now].rival, 'stun'
                    if(RandomPlayer):
                        p[now].reset(1024, random.randint(0, MapHeight))
                    else:
                        p[now].reset(1024, MapHeight/3)
                    live.remove(now)
            
        if(len(live)<1):
            print
            print '---prepare next gene---'
            AISort(s, len(s))
            AICopy(s, t, len(s))
            AICrossover(s, len(s), t, 20)
            AIMutate(t, len(s), 90)
            s = t
            for ai in s:
                ai.rival = 9999
            #s[len(s)-1].reset()
            rd += 1
            #now = 0
            t = []
            '''if(RandomPlayer):
                p.reset(1024, random.randint(0, MapHeight))
            else:
                p.reset(1024, MapHeight/3)'''
            for i in range(0, Size):
                b[i].reset()
                p[i].reset(1024, MapHeight/3)
                live.append(i)
            print '-----------------------'
            print
            print 'Round:', rd
            
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
