# coding : utf-8

class Node:
    def __init__(self):
        self.head = None
        self.blocs = []

    def optimize(self):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")


class StructureNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.members = []


class FunctionNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.ret_type = ""
        self.args_list = []
        # list of nodes
        self.body = []
        self.ret = None


class ValueNode(Node):
    def __init__(self):
        super().__init__()

        self.var_type = ""
        self.value = []


class VarNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.value = None


class ConditionNode(Node):
    def __init__(self):
        super().__init__()

        self.lhs, self.op, self.rhs = [], None, []


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


class WhileNode(Node):
    def __init__(self):
        super().__init__()

        self.condition = None
        # list of instructions
        self.body = []


class ForNode(Node):
    def __init__(self):
        super().__init__()

        self.var = None
        self.container = None
        # list of instructions
        self.body = []


class FunctionCallNode(Node):
    def __init__(self):
        super().__init__()

        self.function_name = ""
        self.args_list = []


class RetNode(Node):
    def __init__(self):
        super().__init__()

        self.ret = []


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
