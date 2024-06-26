from common_functions import Point, parse_input, gen_distance_matrix,  get_road_distance, file_reordered
import math
import sys
import time

def  get_min_row_element(matrix, position):
    min_pos = 0
    starting_pos = 0

    while matrix[position][starting_pos] == 0 and starting_pos < len(matrix)-1:
        starting_pos += 1

    #Security check
    if starting_pos == len(matrix)-1:
        return -1

    min_pos = starting_pos

    min_val = math.inf

    for j in range(starting_pos, len(matrix[position])):
        if matrix[position][j] < min_val and position != j and matrix[position][j] != -1:
            min_pos = j
            min_val = matrix[position][j]

    return min_pos

def clean_position(matrix, pos):
    for col in range(len(matrix)):
        matrix[pos][col] = -1

    for row in range(len(matrix)):
        matrix[row][pos] = -1

def get_best_solution_nna(points):
    road = []
    order = []

    distance_matrix = gen_distance_matrix(points, len(points))

    #We start always at first point 
    last_point = 0
    road.append(points[last_point])
    order.append(0)

    while len(road) < len(points):
        best_position = get_min_row_element(distance_matrix, last_point)

        road.append(points[best_position])
        order.append(best_position)

        clean_position(distance_matrix, last_point)

        last_point = best_position

    road_distance = get_road_distance(road)

    return road, road_distance, order


#file = sys.argv[1]

'''file = sys.argv[1] 

points = parse_input(file)

#start = time.perf_counter()

recorrido, distancia, orden = get_best_solution_nna(points)

print(str(len(points)) + " " + str(distancia))

#end = time.perf_counter()

#total_time = (end-start)

#str_orden = [str(n) for n in orden]

#print(orden)
#print("Su distancia es: " + str(distancia))

#file_reordered(recorrido)



print("El mejor orden a seguir: [" + ','.join(str_orden) + "]")
correct = len(set(orden)) == len(orden) #Checks if there is any duplicate

if correct:
    print("Correct order!")
else:
    print("Incorrect order")


print("Su distancia es: " + str(distancia))

number = file.split("./Datasets/")
number = number[1].split(".tsp")
print(number)
number = int(number[0])'''

#print(str(len(points)) + " " + str(total_time))