import numpy as np
import networkx as nx
import matplotlib.pyplot as plt

def main():

    print('Beginning program...')

    # Regular graph
    graph = nx.Graph()

    graph.add_node('A')
    graph.add_node('B')
    graph.add_node('C')
    graph.add_node('D')
    graph.add_node('E')

    graph.add_edge('A', 'B')
    graph.add_edge('A', 'C')
    graph.add_edge('A', 'D')

    graph.add_edge('B', 'C')
    graph.add_edge('B', 'D')

    graph.add_edge('D', 'E')

    fig, axes = plt.subplots(3, 2)

    nx.draw(
        graph,
        ax=axes[0,0],
    )
    axes[0,0].set_title('nx.draw()')

    nx.draw_networkx(
        graph,
        ax=axes[0,1],
    )
    axes[0,1].set_title('nx.draw_networkx()')

    nx.draw_spring(
        graph,
        ax=axes[1,0]
    )
    axes[1,0].set_title('nx.draw() spring_layout')

    nx.draw_networkx(
        graph,
        ax=axes[1,1],
        layout='spring'
    )
    axes[1,1].set_title('nx.draw_networkx() spring_layout')

    nx.draw_circular(
        graph,
        ax=axes[2,0]
    )
    axes[2,0].set_title('nx.draw() circular_layout')

    nx.draw_networkx(
        graph,
        ax=axes[2,1],
        layout='circular'
    )
    axes[2,1].set_title('nx.draw_networkx() circular_layout')

    plt.setp(axes, xticks=[], yticks=[])
    plt.show()

    # Complete Graph
    nonagon_graph = nx.complete_graph(9)

    fig, axes = plt.subplots(1, 2)

    nx.draw_networkx(
        nonagon_graph,
        ax=axes[0]
    )
    axes[0].set_title('Default (spring layout) complete_graph()')

    nx.draw_circular(
        nonagon_graph,
        ax=axes[1]
    )
    axes[1].set_title('Nonagon infinity circular_layout')

    plt.setp(axes, xticks=[], yticks=[])
    plt.show()

if __name__ == '__main__':
    main()
