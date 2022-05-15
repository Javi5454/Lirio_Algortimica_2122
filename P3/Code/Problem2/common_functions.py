#Creating a struct point
from cmath import sqrt
from dataclasses import dataclass
import math


@dataclass
class Point:
    x: float
    y:float

def parse_input(input):
    points = []

    with open(input, "r") as archive:
        archive.readline()

        for line in archive.readlines():
            line = line.strip().split(' ')

            p = Point(float(line[1]), float(line[2]))

            points.append(p)
    return points

def distance(p1,p2):
    if p1 != p2:
        result = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2))
        result = round(result.real)
    else:
        result = 0
    return result


def gen_distance_matrix(points, num_cities):
    matrix = [[0 for x in range(num_cities)] for x in range(num_cities)]

    for i in range(num_cities):
        for j in range(num_cities):
            matrix[i][j] = distance(points[i], points[j])

    return matrix


def get_road_distance(road):
    road_distance = 0

    for i in range(len(road)-1):
        road_distance += distance(road[i], road[i+1])

    #First and last point
    road_distance += distance(road[0], road[len(road)-1])

    return road_distance
