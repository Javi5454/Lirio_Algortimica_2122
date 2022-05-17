def get_worst_node(road): #O(n)
    worst_distance = distance(road[0], road[1]) #O(1)
    worst_pos = 0 #O(1)

    for i in range(len(road)-1): #O(n)
        if distance(road[i],road[i+1]) > worst_distance: #O(1)
            worst_distance = distance(road[i],road[i+1]) #O(1)
            worst_pos = i

    return worst_pos

#Perturbate the road from a pos
def perturbate(road, orden, pos): #O(n^2)

    best_perturbation = pos #O(1)
    base_distance = get_road_distance(road) #O(n)

    #Calcualte all perturbations
    for i in range(len(road)): #O(n)                            |
        current_perb = copy.deepcopy(road) #O(n)                |
        current_perb = get_swap(current_perb, pos, i) #O(1)     | #O(n^2)
        swap_distance = get_road_distance(current_perb) #O(n)   |
        
        if swap_distance < base_distance: #O(1)                 |
            best_perturbation = i #O(1)                         |
            base_distance = swap_distance #O(1)                 |

    #Make the change with the best perturbation
    road = get_swap(road, pos, best_perturbation) #O(1)
    orden = get_swap(orden, pos, best_perturbation) #O(1)



def get_best_solution_perturbations(points, orden, perturbations):
    base_road = points #O(1)

    for i in range(perturbations): #O(perturbations)     |
        pos = get_worst_node(points) #O(n)              |
                                                    #   | O(n^2*perturbations)
        perturbate(base_road,orden, pos) #O(n^2)        |

    return base_road, get_road_distance(base_road), orden

file = sys.argv[1] #"./Problem2/Datasets/ulysses16.tsp"  
perturbations =  int(sys.argv[2])

points = parse_input(file)

start = time.perf_counter()

base_road, distance_nna, orden = get_best_solution_nna(points)

final_road, final_distance, final_orden = get_best_solution_perturbations(base_road, orden, perturbations)

end = time.perf_counter()


correct = len(set(final_orden)) == len(final_orden) #Checks if there is any duplicate

'''if correct:
    print("Correct order!")
else:
    print("Incorrect order")'''

#print(final_orden)
#print("Su distancia es: " + str(final_distance))

# file_reordered(final_road)

time_total = end-start

print(str(len(points)) + " " + str(time_total))
