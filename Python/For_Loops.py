import turtle

def printManyThings():
    for num in range(5, 101, 5):
        print(num)
    print("answer to question 3 is: 20") 

def drawSpiral(myTurtle, maxSide):
    for sideLength in range(5, maxSide + 1, 5):
        myTurtle.forward(sideLength)
        myTurtle.right(90)

def drawOctagon(myTurtle, sideLength):
    for side in range(8):
        myTurtle.forward(sideLength)
        myTurtle.right(360 / 8)

def drawPolygon(myTurtle, sideLength, numSide):
    turnAngle = 360 / numSide
    for i in range(numSide):
        myTurtle.forward(sideLength)
        myTurtle.right(turnAngle)

def drawCircle(myTurtle, radius):
    circumference = 2 * 3.14 * radius
    sideLen = circumference / 360 
    drawPolygon(myTurtle, sideLen, 360)

printManyThings()

bob = turtle.Turtle()
bob.speed('fastest')

drawSpiral(bob, 100)

drawOctagon(bob, 50)

drawPolygon(bob, 100, 3)

drawPolygon(bob, 70, 6)

drawCircle(bob, 50)

bob.penup()
bob.goto(-25, (-25) ** 2)
bob.pendown()

for x in range(-25, 26):
    y = x ** 2
    bob.goto(x, y)

turtle.done()
