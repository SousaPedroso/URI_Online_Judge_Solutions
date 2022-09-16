# -*- coding: utf-8 -*-

num_test_cases = int(input())
trash = input() # Blank line after input

tree_species = {} # Store the species of trees observed
tot_species = 0 # Total species in a test case
case = 0 # Current number of test cases

while case < num_test_cases:
    try:
        specie = input()
    except EOFError as e:
        specie = ""
    # New test case
    if specie == '':
        for each_specie in sorted(tree_species.keys()):
            print("%s %2.4f" %(each_specie, 100*(tree_species.get(each_specie)/tot_species)))
        
        tot_species = 0
        case += 1
        tree_species = {}
        if case != num_test_cases:
            print()
    else:
        tot_species += 1
        # Value in the dictionary
        num_species = tree_species.get(specie)
        tree_species[specie] = num_species + 1 if num_species is not None else 1