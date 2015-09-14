import pygame
import random
import math
from sys import exit

pygame.init()
pygame.mouse.set_visible(0)

ScreenWidth = 1024
ScreenHeight = 600

screen = pygame.display.set_mode((ScreenWidth, ScreenHeight), 0, 32)

pygame.display.set_caption("Evo")

bg = pygame.image.load('gra.PNG').convert()
bla = pygame.image.load('black.PNG').convert()

MapWidth = bg.get_width()
MapHeight = bg.get_height()

LGoal_x = 0
LGoal_y = MapHeight / 2
LGoal_xBorder = 44

RGoal_x = MapWidth
RGoal_y = MapHeight / 2
RGoal_xBorder = 979

Goal_TBorder = 210
Goal_DBorder = 390

rplayer = pygame.image.load('red.png').convert_alpha()
bplayer = pygame.image.load('blue.png').convert_alpha()
ball = pygame.image.load('ball.jpg').convert_alpha()
door = pygame.image.load('door.png').convert_alpha()

rpimg_height = rplayer.get_height()
rpimg_width = rplayer.get_width()
bpimg_height = bplayer.get_height()
bpimg_width = bplayer.get_width()

bimg_height = ball.get_height()
bimg_width = ball.get_width()

dimg_height = door.get_height()
dimg_width = door.get_width()

AI_KickAura = 8
