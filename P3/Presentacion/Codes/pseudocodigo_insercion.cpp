ALGORITMO INSERCION TSP (G=(V,R))
C = V [C = Lista de Candidatos]
S = Vacio [S = Conjunto Solucion]
Crear a partir de R recorridoInicial
S << {este, oeste, norte}
C = C\{este, oeste, norte}
Fin de Crear
Repetir hasta que cardinal(C)= Vacio
	Crear vector pCandidatos
	Para cada s en S
		Para cada c en C
			Calcular distancia(s,c)
			Seleccionar punto cercano de C al punto "s"
		Fin-Para
	Almacenar (c,distancia) >> puntosCandidatos
	Fin de Para
	Seleccionar p en puntosCandidatos que produzca menor incremento
	Insertar p en T
	C = C\{p}
Fin de Repetir