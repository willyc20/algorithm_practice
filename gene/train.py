import math
import random


def sigmoid(s):
    #return 1 / (1 + pow(math.e, s * -2))
    return math.tanh(-5*s)

class Swag:

    def __init__(self, ih, co, ho):
        self.rival = 9999
        self.incell = [0, 0, 0 ,0]
        self.hiddencell = [0, 0, 0 ,0, 0]
        self.hiddencell2 = [0, 0, 0, 0, 0]
        self.outcell = [0, 0, 0 ,0, 0, 0, 0, 0]
        self.counter = 0

        if(ih == 0):
        
            self.ihwag = [[0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0]]
            for i in range(0, 4):
                for j in range(0, 5):
                    while(self.ihwag[i][j] == 0):
                        self.ihwag[i][j] = float(random.randint(-100, 100)) / 100.0

        else:
            self.ihwag = ih

        if(co == 0):

            self.cowag = [[0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0]]

            for i in range(0, 5):
                for j in range(0, 5):
                    while(self.cowag[i][j] == 0):
                        self.cowag[i][j] = float(random.randint(-100, 100)) / 100.0
        else:

            self.cowag = co

        if(ho == 0):

            self.howag = [[0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0],
                          [0, 0, 0, 0, 0, 0, 0, 0]]
            for i in range(0, 5):
                for j in range(0, 8):
                    while(self.howag[i][j] == 0):
                        self.howag[i][j] = float(random.randint(-100, 100)) / 100.0

        else:
            self.howag = ho

    def reset(self):
        self.ihwag = [[0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0]]
        for i in range(0, 4):
            for j in range(0, 5):
                while(self.ihwag[i][j] == 0):
                    self.ihwag[i][j] = float(random.randint(-100, 100)) / 100.0

        self.cowag = [[0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0]]

        for i in range(0, 5):
            for j in range(0, 5):
                while(self.cowag[i][j] == 0):
                    self.cowag[i][j] = float(random.randint(-100, 100)) / 100.0

        self.howag = [[0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0],
                      [0, 0, 0, 0, 0, 0, 0, 0]]
        for i in range(0, 5):
            for j in range(0, 8):
                while(self.howag[i][j] == 0):
                        self.howag[i][j] = float(random.randint(-100, 100)) / 100.0

    def comp(self, p, soccer):
        self.incell[0] = p.x
        self.incell[1] = p.y
        self.incell[2] = soccer.x
        self.incell[3] = soccer.y
        for i in range(0, 4):
            for j in range(0, 5):
                self.hiddencell[j] += self.ihwag[i][j] * self.incell[i]
                
        for i in range(0, 5):
            self.hiddencell[i] = sigmoid(self.hiddencell[i])
            if(abs(self.hiddencell[i]) < 0.3):
                self.hiddencell[i] = 0

        for i in range(0, 5):
            for j in range(0, 5):
                self.hiddencell2[j] += self.cowag[i][j] * self.hiddencell[i]

        for i in range(0, 5):
            if(abs(self.hiddencell2[i]) < 0.3):
                self.hiddencell2[i] = 0

        for i in range(0, 5):
            for j in range(0, 8):
                self.outcell[j] += self.howag[i][j] * self.hiddencell2[i]

        for i in range(0, 8):
            self.outcell[i] = sigmoid(self.outcell[i])
            if(abs(self.outcell[i]) < 0.3):
                self.outcell[i] = 0

        ri = math.sqrt((p.x - soccer.x) * (p.x - soccer.x) + (p.y - soccer.y) * (p.y - soccer.y))
        if(ri < self.rival):
            self.rival = ri
        else:
            self.counter += 1
        #print self.rival

def AISort(p, n):
      for i in range(0,n):
            for j in range(0, n-i-1):
                  if(p[j].rival > p[j+1].rival):
                        t = p[j]
                        p[j] = p[j+1]
                        p[j+1] = t

def AICopy(p, t, n):
      for i in range(0, n / 2):
            t.append(p[i])

def AIMutate(p, n, rate):
    for ai in p:
        r = random.randint(0, 100)
        if(r > rate):
            print 'Mutate'
            r = random.randint(0, 20 - 1)
            ai.ihwag[r / 5][r % 5] = float(random.randint(-100, 100)) / 100.0
        r = random.randint(0, 100)
        if(r > rate):
            print 'Mutate'
            r = random.randint(0, 25 - 1)
            ai.cowag[r / 5][r % 5] = float(random.randint(-100, 100)) / 100.0
        r = random.randint(0, 100)
        if(r > rate):
            print 'Mutate'
            r = random.randint(0, 40 - 1)
            ai.howag[r / 8][r % 8] = float(random.randint(-100, 100)) / 100.0
        

def AICrossover(p, n, e, rate):
    for ll in range(n / 2, n):
        ss = []
        ss.append(p[random.randint(0, n - 1)])
        ss.append(p[random.randint(0, n - 1)])
        AISort(ss, 2)
        r = random.randint(0, 100)
        if(r > rate):
            print 'Crossover'
            t = []
            counter = 0
            ih = []
            co = []
            ho = []
            k1 = random.randint(0, 20 - 1)
            k2 = random.randint(0, 25 - 1)
            k3 = random.randint(0, 40 - 1)
            for i in range(0, k1):
                t.append(ss[0].ihwag[i / 5][i % 5])
                counter += 1
                if(counter >= 5):
                        ih.append(t)
                        t = []
                        counter = 0
            for i in range(k1, 20):
                t.append(ss[1].ihwag[i / 5][i % 5])
                counter += 1
                if(counter >= 5):
                    ih.append(t)
                    t = []
                    counter = 0
            for i in range(0, k2):
                t.append(ss[0].cowag[i / 5][i % 5])
                counter += 1
                if(counter >= 5):
                        co.append(t)
                        t = []
                        counter = 0
            for i in range(k2, 25):
                t.append(ss[1].cowag[i / 5][i % 5])
                counter += 1
                if(counter >= 5):
                    co.append(t)
                    t = []
                    counter = 0
            for i in range(0, k3):
                t.append(ss[0].howag[i / 8][i % 8])
                counter += 1
                if(counter >= 8):
                    ho.append(t)
                    t = []
                    counter = 0
            for i in range(k3, 40):
                t.append(ss[1].howag[i / 8][i % 8])
                counter += 1
                if(counter >= 8):
                    ho.append(t)
                    t = []
                    counter = 0
            e.append(Swag(ih, co, ho))
        else:
            e.append(ss[0])
