#!/usr/bin/python3
"""Write a method that determines if all the boxes can be opened."""


def canUnlockAll(boxes):
    """ Ensemble pour stocker les boîtes déjà ouvertes"""
    opened_boxes = set()
    """ Ajouter la première boîte (boîte 0) à l'ensemble des boîtes ouvertes"""
    opened_boxes.add(0)
    """ Pile pour suivre les boîtes à explorer"""
    stack = [0]
    """ Tant qu'il reste des boîtes à explorer dans la pile """
    while stack:
        current_box = stack.pop()
        for key in boxes[current_box]:
            if 0 <= key < len(boxes) and key not in opened_boxes:
                opened_boxes.add(key)
                stack.append(key)

    return len(opened_boxes) == len(boxes)
