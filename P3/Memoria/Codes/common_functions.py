#Creating a struct point
@dataclass
class Point:
    x: float
    y:float

def parse_input(input):
    points = []

    with open(input, "r") as archive:
        archive.readline()

        for line in archive.readlines():
            line = " ".join(line.split())
            line = line.strip().split(' ')

            p = Point(float(line[1]), float(line[2]))

            points.append(p)
    return points

def distance(p1,p2): #O(1)
    if p1 != p2: #O(1)
        result = sqrt(pow((p1.x - p2.x),2) + pow((p1.y - p2.y),2)) #O(1)
        result = round(result.real) #O(1)
    else:
        result = 0 #O(1)
    return result


def gen_distance_matrix(points, num_cities): #O(n^2)
    matrix = [[0 for x in range(num_cities)] for x in range(num_cities)] #O(n^2)

    for i in range(num_cities): #O(n)                           |
        for j in range(num_cities): #O(n)                       | O(n^2)
            matrix[i][j] = distance(points[i], points[j]) #O(1) |

    return matrix


def get_road_distance(road): #O(n)
    road_distance = 0 #O(1)

    for i in range(len(road)-1): #O(n)
        road_distance += distance(road[i], road[i+1]) #O(1)

    #First and last point
    road_distance += distance(road[0], road[len(road)-1]) #O(1)
    return road_distance

def file_reordered(points):
    for point in points:
        print(str(point.x) + " " + str(point.y))

def get_swap(road, pos1, pos2): #O(1)
    changed = road

    tmp = road[pos1]
    road[pos1] = road[pos2]
    road[pos2] = tmp

    return changed
