from common_functions import Point, parse_input, distance, gen_distance_matrix,  get_road_distance, file_reordered, get_swap
from cercania import get_best_solution_nna
import sys
import copy
import time

#Find the most separated nodes (only one of them)
def get_worst_node(road):
    worst_distance = distance(road[0], road[1])
    worst_pos = 0

    for i in range(len(road)-1):
        if distance(road[i],road[i+1]) > worst_distance:
            worst_distance = distance(road[i],road[i+1])
            worst_pos = i

    return worst_pos

#Perturbate the road from a pos
def perturbate(road, orden, pos):

    best_perturbation = pos
    base_distance = get_road_distance(road)

    #Calcualte all perturbations
    for i in range(len(road)):
        current_perb = copy.deepcopy(road)
        current_perb = get_swap(current_perb, pos, i)
        swap_distance = get_road_distance(current_perb)
        
        if swap_distance < base_distance:
            best_perturbation = i
            base_distance = swap_distance

    #Make the change with the best perturbation
    road = get_swap(road, pos, best_perturbation)
    orden = get_swap(orden, pos, best_perturbation)



def get_best_solution_perturbations(points, orden, perturbations):
    base_road = points

    for i in range(perturbations):
        pos = get_worst_node(points)

        perturbate(base_road,orden, pos)

    return base_road, get_road_distance(base_road), orden

file = sys.argv[1] #"./Problem2/Datasets/ulysses16.tsp"  
perturbations =  int(sys.argv[2])

points = parse_input(file)

base_road, distance_nna, orden = get_best_solution_nna(points)

start = time.perf_counter()

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