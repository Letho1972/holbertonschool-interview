#!/usr/bin/python3
"""
Units of water
"""
def rain(walls):

    """
    calculate how many square units of water
    will be retained after it rains.
    """

    # Si la liste est vide, il n'y a pas d'eau à retenir, donc on retourne 0
    if not walls:
        return 0

    # Initialisation des deux pointeurs:
    # 'left' commence au début de la liste et 'right' à la fin
    left, right = 0, len(walls) - 1

    # Initialisation des hauteurs maximales rencontrées jusqu'à présent
    left_max, right_max = walls[left], walls[right]

    # Variable pour accumuler la quantité totale d'eau retenue
    water_trapped = 0

    # Boucle tant que les deux pointeurs ne se croisent pas
    while left < right:
        # Si la hauteur max à gauche est inférieure ou égale à celle à droite
        if left_max <= right_max:
            # Déplacer le pointeur 'left' vers la droite
            left += 1
            # Mettre à jour la hauteur max à gauche
            left_max = max(left_max, walls[left])
            # Calculer l'eau retenue à la position actuelle et ajouter au total
            water_trapped += max(0, left_max - walls[left])
        else:
            # Si la hauteur max à droite est inférieure à celle à gauche
            # Déplacer le pointeur 'right' vers la gauche
            right -= 1
            # Mettre à jour la hauteur max à droite
            right_max = max(right_max, walls[right])
            # Calculer l'eau retenue à la position actuelle et ajouter au total
            water_trapped += max(0, right_max - walls[right])

    # Retourner la quantité totale d'eau retenue
    return water_trapped
