import matplotlib.pyplot as plt

# Dimensiones y puntos generados
dimensiones = [10, 50, 100, 500, 1000, 2000, 5000]
puntos_por_dimension = {}  # Almacenará los puntos para cada dimensión

# Generar 100 puntos aleatorios entre 0 y 1 para cada dimensión
for dim in dimensiones:
    puntos = np.random.rand(100, dim)  # Generar 100 puntos de dimensión 'dim'
    puntos_por_dimension[dim] = puntos

# Crear un histograma para cada dimensión
for dim in dimensiones:
    puntos_dimension_actual = puntos_por_dimension[dim]
    # Tomar la primera columna para el histograma
    puntos_para_histograma = puntos_dimension_actual[:, 0]

    # Elegir el número de bins apropiado (por ejemplo, 20 bins)
    num_bins = 20

    # Crear el histograma
    plt.hist(puntos_para_histograma, bins=num_bins, edgecolor='black')

    # Añadir etiquetas y título
    plt.xlabel('Valor')
    plt.ylabel('Frecuencia')
    plt.title(f'Histograma de la Primera Columna para Dimensión {dim}')

    # Mostrar el histograma
    plt.show()
