#!/usr/bin/python3
import re
import os
import argparse
from graphviz import Digraph


def read_dir_path():
    parser = argparse.ArgumentParser(
        description='Process the path to a directory.'
    ) 
    parser.add_argument(
        'dir_path', type=str, help='The path to the directory.',
    )
    args = parser.parse_args()
    dir_path = args.dir_path
    return dir_path


def find_includes(file_path):
    includes = set()
    with open(file_path, 'r') as file:
        for line in file:
            match = re.match(r'#include "(.*)"', line)
            if match:
                includes.add(match.group(1))
    return includes


def build_dependency_graph(project_dir):
    graph = {}
    for root, dirs, files in os.walk(project_dir):
        for file in files:
            if file.endswith('.c') or file.endswith('.h'):
                file_path = os.path.join(root, file)
                includes = find_includes(file_path)
                graph[file] = includes
    return graph


def visualize_graph(graph):
    dot = Digraph(comment='Dependency Graph')
    for node, edges in graph.items():
        dot.node(node)
        for edge in edges:
            dot.edge(node, edge)
    dot.render('dependency_graph.gv', view=True)


if __name__ == "__main__":
    project_dir = read_dir_path()
    graph = build_dependency_graph(project_dir)
    visualize_graph(graph)

