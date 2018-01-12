# coding : utf-8

class Node:
    def __init__(self):
        self.head = None
        self.blocs = []

    def getBytecode(self):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")

    def optimize(self):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")


class StructureNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.members = []

    def getBytecode(self):
        pass

    def optimize(self):
        for node in self.members:
            node.optimize()


class FunctionNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.ret_type = ""
        self.args_list = []
        # list of nodes
        self.body = []
        self.ret = None

    def getBytecode(self):
        pass

    def optimize(self):
        for node in self.body:
            node.optimize()


class ValueNode(Node):
    def __init__(self):
        super().__init__()

        self.var_type = ""
        self.value = []

    def getBytecode(self):
        pass

    def optimize(self):
        for node in self.value:
            node.optimize()


class VarNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.value = None

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class ConditionNode(Node):
    def __init__(self):
        super().__init__()

        self.lhs, self.op, self.rhs = [], None, []

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class IfNode(Node):
    def __init__(self):
        super().__init__()

        self.condition = None
        # list of instructions
        self.body = []
        # list of instructions (`IfNode`s)
        self.elifs_clause = []
        # `IfNode` with no condition
        self.else_clause = None

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class WhileNode(Node):
    def __init__(self):
        super().__init__()

        self.condition = None
        # list of instructions
        self.body = []

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class ForNode(Node):
    def __init__(self):
        super().__init__()

        self.var = None
        self.container = None
        # list of instructions
        self.body = []

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class FunctionCallNode(Node):
    def __init__(self):
        super().__init__()

        self.function_name = ""
        self.args_list = []

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class RetNode(Node):
    def __init__(self):
        super().__init__()

        self.ret = []

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class AST:
    def __init__(self):
        self.nodes = []

    def __iter__(self):
        for node in self.nodes:
            yield node

    def addNode(self, node):
        self.nodes.append(node)

    def getBytecode(self):
        return b""

    def getRepr(self):
        return ""


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")
