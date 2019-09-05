import argparse

import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

def main():

    parser = argparse.ArgumentParser(description='Generate a random graph of specified size')
    parser.add_argument(
        '-N',
        '--nodes',
        type=int,
        action='store',
        metavar='number-nodes',
        required=True,
        help='amount of nodes in the graph'
    )
    args = parser.parse_args()

    node_list = []
    for node_ix in range(args.nodes):
        node_list.append('Node {}'.format(node_ix))

    graph = nx.Graph()
    graph.add_nodes_from(node_list)

    print('\nNodes in graph: ')
    for node in graph:
        print(node)

    plt.figure()
    nx.draw_networkx(
        graph
    )
    plt.show()

if __name__ == '__main__':
    main()
