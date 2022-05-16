def perturbate(road, orden, pos):
    current_perb = road
    best_gain = math.inf
    best_perturbation = pos
    base_distance = get_road_distance(road)

    for i in range(len(road)):
        current_perb = get_swap(road, pos, i)
        swap_distance = get_road_distance(current_perb)
        
        if swap_distance < base_distance:
            best_perturbation = i
            base_distance = swap_distance

    road = get_swap(road, pos, best_perturbation)
    orden = get_swap(orden, pos, best_perturbation)

def get_best_solution_perturbations(points, orden, perturbations):
    base_road = points

    for i in range(perturbations):
        pos = get_worst_node(points)

        perturbate(base_road,orden, pos)

    return base_road, get_road_distance(base_road), orden
