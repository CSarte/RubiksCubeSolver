# minimax_alphabeta2.py
# Simple example of minimax algorithm with alpha-beta pruning.

import argparse
import math

parser = argparse.ArgumentParser(description="Run minimax with alpha-beta pruning on a game tree")
parser.add_argument('--verbose', action='store_true', help="display detailed search")

def main(args):
    tree = {
        'A': ['B', 'C', 'D'],
        'B': [2, 'E', 2],
        'C': [8, 7, 'F'],
        'D': [10, 5, 'G'],
        'E': [4, 8],
        'F': [6, 1, 12],
        'G': [9, 7]}
    depth = limit 
    action, utility = minimax(tree, 'A', 'max', True)
    print(f"The best action is {action} with utility {utility}")
    
#ad depth parameter and everytime called subtract one
def minimax(tree, node, which_player, alpha=-math.inf, beta=math.inf, verbose=True):
    """Apply minimax with alpha-beta pruning to a node in the tree for the given player."""

    # Check if we have reached a terminal node
    if is_terminal(node):
        if verbose: print(f'\tterminal node {node}')
        return node, node
    
    children = tree[node]

    # Search for the max player
    if which_player == "max":
        value = -math.inf
        best_action = None
        for child in children:
            if verbose: print(f'max: searching {node}-->{child} (\u03b1, \u03b2)=({alpha},{beta})')
            alpha = max(alpha, value)
            if alpha >= beta:
                if verbose: print(f'\t(\u03b1, \u03b2)=({alpha},{beta}) --> PRUNE!')
                break
            _, utility = minimax(tree, child, 'min', alpha, beta, verbose=verbose)
            
            if utility > value :
                value = utility 
                best_action = child 
        return best_action, value
    
    # Search for the min player
    if which_player == "min":
        value = math.inf
        for child in children:
            if verbose: print(f'min: searching {node}-->{child} (\u03b1, \u03b2)=({alpha},{beta})')
            beta = min(beta, value)
            if alpha >= beta:
                if verbose: print(f'\t(\u03b1, \u03b2)=({alpha},{beta}) --> PRUNE!')
                break
            action, utility = minimax(tree, child, 'max', alpha, beta, verbose=verbose)
            value = min(value, utility)
        return action, value
    
def is_terminal(node):
    """Is the current state a terminal node."""
    return isinstance(node, int)

if __name__ == '__main__':
    main(parser.parse_args())