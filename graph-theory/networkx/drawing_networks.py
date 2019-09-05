import networkx as nx

def main():

    print('Beginning program...')

    graph = nx.Graph()
    print(type(graph))

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

    print('\nNodes in graph: ')
    for node in graph:
        print(node)

    print('\nEdges in graph: ')
    for edge_pair in graph.edges:
        print(edge_pair)

    for edge, color in graph.edges.data('color'):
        print(edge, color)

if __name__ == '__main__':
    main()
