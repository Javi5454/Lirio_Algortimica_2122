def  get_min_row_element(matrix, position): #O(n)
    min_pos = 0 #O(1)
    starting_pos = 0 #O(1)

    while matrix[position][starting_pos] == 0 and starting_pos < len(matrix)-1: #O(n)
        starting_pos += 1

    #Security check
    if starting_pos == len(matrix)-1: #O(1)
        return -1

    min_pos = starting_pos #O(1)

    min_val = math.inf #O(1)

    for j in range(starting_pos, len(matrix[position])): #O(n)
        if matrix[position][j] < min_val and position != j and matrix[position][j] != -1: #O(1)
            min_pos = j
            min_val = matrix[position][j]

    return min_pos

def clean_position(matrix, pos): #O(n)
    for col in range(len(matrix)): #O(n)
        matrix[pos][col] = -1

    for row in range(len(matrix)): #O(n)
        matrix[row][pos] = -1

def get_best_solution_nna(points): #O(n^2)
    road = []
    order = []

    distance_matrix = gen_distance_matrix(points, len(points)) #O(n^2)

    #We start always at first point 
    last_point = 0 #O(1)
    road.append(points[last_point]) #O(1)
    order.append(0) #O(1)

    while len(road) < len(points):              #                               |
        best_position = get_min_row_element(distance_matrix, last_point) #O(n)  |
                                                                            #   |
        road.append(points[best_position]) #O(1)                            #   |
        order.append(best_position) #O(1)                                   #   |   O(n^2)
                                                                            #   |
        clean_position(distance_matrix, last_point) #O(n)                       |
                                                                            #   |
        last_point = best_position #O(1)                                        |

    road_distance = get_road_distance(road) #O(1)

    return road, road_distance, order


file = sys.argv[1]

points = parse_input(file)

recorrido, distancia, orden = get_best_solution_nna(points)

str_orden = [str(n) for n in orden]

print("El mejor orden a seguir: [" + ','.join(str_orden) + "]")
print("Su distancia es: " + str(distancia))
