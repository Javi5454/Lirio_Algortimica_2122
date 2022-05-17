#Find the most separated nodes (only one of them)
def get_worst_node(road): #O(n)
    worst_distance = distance(road[0], road[1]) #O(1)
    worst_pos = 0 #O(1)

    for i in range(len(road)-1): #O(n)
        if distance(road[i],road[i+1]) > worst_distance: #O(1)
            worst_distance = distance(road[i],road[i+1]) #O(1)
            worst_pos = i #O(1)

    return worst_pos

#Perturbate the road from a pos
def perturbate(road, orden, pos): #O(n^2)
    current_perb = road #O(1)
    best_gain = math.inf #O(1)
    best_perturbation = pos #O(1)
    base_distance = get_road_distance(road) #O(n)

    #Calcualte all perturbations
    for i in range(len(road)): #O(n)                            |
        current_perb = get_swap(road, pos, i) #O(1)             | O(n^2)
        swap_distance = get_road_distance(current_perb) #O(n)   |
        
        if swap_distance < base_distance: #O(1)
            best_perturbation = i #O(1)
            base_distance = swap_distance #O(1)

    #Make the change with the best perturbation
    road = get_swap(road, pos, best_perturbation) #O(1)
    orden = get_swap(orden, pos, best_perturbation) #O(1)



def get_best_solution_perturbations(points, orden, perturbations): #O(n^2*perturbaciones)
    base_road = points #O(1)

    for i in range(perturbations): #O(perturbaciones)
        pos = get_worst_node(points) #O(n)

        perturbate(base_road,orden, pos) #O(n^2)

    return base_road, get_road_distance(base_road), orden
