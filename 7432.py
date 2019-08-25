n = int(input())
ls = [input() for _ in range(n)]

def order_dict(dictionary, layer):
    result = {}
    for k, v in sorted(dictionary.items()):
        if isinstance(v, dict):
            print(' ' * layer + k)
            result[k] = order_dict(v, layer+1)

    return result

tree = dict()
for name in ls:
    here = tree
    for a in name.split('\\'):
        if a not in here:
            here[a] = dict()
        here = here[a]

order_dict(tree, layer=0)
