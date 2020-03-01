import pygame
import random
from pygame.locals import *

pygame.init()

screen = pygame.display.set_mode((640, 480))          # sets the window size
pygame.display.set_caption('Snake? Snake! SNAKE!!!!') # sets the titlebar
pygame.mouse.set_visible(0)

clock = pygame.time.Clock()     # get a clock for the main loop
running = True                  # and keep account of whether we need to stop

up = 0          #definiting the directions
right = 1
down = 2
left = 3

def randPos():
    return ((random.randint(0, 31), random.randint(0, 23)))

def newFruitPos():
    out = randPos()
    while out in snakePos:
        out = randPos()

    return out

snakePos = [(0, 0), (1, 0), (2, 0)] # and the initial snake position
snakeDir = down

# Task: Add fruit
fruitPos = newFruitPos()

gridSize = (32, 24)         # defines the size of the game grid for reference

updateInvFreq = 5           # sets how many frames it takes for the game to
                            # update

snakeSquare = pygame.Surface((20, 20))  # this is how to define a rectangle
snakeSquare.fill(pygame.Color("red"))   # of size 20x20 for drawing

fruitSquare = pygame.Surface((20, 20))  # this is how to define a rectangle
fruitSquare.fill(pygame.Color("green"))   # of size 20x20 for drawing

background = pygame.Surface((640, 480))
background.fill(pygame.Color("black"))


def handleEvents():
    global snakeDir         # we will need to modify the snake direction here
    global running          # and whether the game is running
    for event in pygame.event.get():    # for every action that we have taken
        if event.type == QUIT:          # if we pressed the close button, quit
            running = False
            # Task: Implement directions
        elif event.type == KEYDOWN and event.key == K_ESCAPE:
            running = False
        elif event.type == KEYDOWN and event.key == K_LEFT:
            snakeDir = (snakeDir - 1)%4
        elif event.type == KEYDOWN and event.key == K_RIGHT:
            snakeDir = (snakeDir + 1)%4

def update():
    global snakePos     # we'll need to update all these variables
    global running
    global fruitPos

    (x, y) = snakePos[0]    # get the first position and update it depending on the direction
    if snakeDir == up:
        y = (y - 1) % gridSize[1]
    elif snakeDir == down:
        y = (y + 1) % gridSize[1]
    elif snakeDir == left:
        x = (x - 1) % gridSize[0]
    elif snakeDir == right:
        x = (x + 1) % gridSize[0]
    else:
        raise Exception(
            "The direction of the snake isn't valid: " +
            str(snakeDir)
        )

    if (x, y) in snakePos:
        running = False

    snakePos.insert(0, (x, y))  # add the new position to the snake

    # Task: Add fruit logic
    if fruitPos[0] == x and fruitPos[1] == y:
        fruitPos = newFruitPos()
        updateInvFreq = len()
    else:
        snakePos.pop() # and remove the old one so it doesn't grow

def draw():
    screen.blit(background, (0, 0)) # clear the screen with the black rectangle

    # Task: draw fruit
    screen.blit(fruitSquare, ((fruitPos[0] * 20), (fruitPos[1] * 20)))

    # Task: draw longer snake
    for snakeBlock in snakePos:
        screen.blit(snakeSquare, ((snakeBlock[0] * 20), (snakeBlock[1] * 20)))

    # and flip the screen
    pygame.display.flip()


# counts how many frames have passed since the last update
updateCounter = 0

# the main loop
while running:
    # synchronize the game with the display
    clock.tick(60)
    # get the events
    handleEvents()

    # if enough frames have passed, update
    if (updateCounter == 0):
        update()

    # redraw everything
    draw()
    updateCounter = (updateCounter + 1) % updateInvFreq

pygame.quit()
