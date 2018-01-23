# coding : utf-8

class Node:
    def __init__(self):
        self.head = None
        self.blocs = []

    def getRepr(self, level=0):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")

    def getBytecode(self):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")

    def optimize(self):
        raise NotImplementedError("This functionnality isn't implemented for a basic node")


class StructureNode(Node):
    def __init__(self):
        super().__init__()

        self.name = ""
        self.members = []

    def getRepr(self, level=0):
        output = "{}<StructureNode `{}`>\n".format("\t" * level, self.name)
        for node in self.members:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</StructureNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<FunctionNode `{}` -> {}>\n".format("\t" * level, self.name, self.ret_type)
        for node in self.args_list:
            output += node.getRepr(level + 1) + "\n"
        output += "\n"
        for node in self.body:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</FunctionNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<ValueNode ({})>\n".format("\t" * level, self.var_type)
        for node in self.value:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</ValueNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<VarNode `{}`>\n".format("\t" * level, self.name)
        output += self.value.getRepr(level + 1)
        output += "{}</ValueNode>".format("\t" * level)

        return output

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class ConditionNode(Node):
    def __init__(self):
        super().__init__()

        self.lhs, self.op, self.rhs = [], None, []

    def getRepr(self, level=0):
        output = "{}<ConditionNode>\n".format("\t" * level)
        for node in self.lhs:
            output += node.getRepr(level + 1) + "\n"
        output += "\n"
        output += self.op.getRepr(level + 1)
        output += "\n"
        for node in self.rhs:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</ConditionNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<IfNode>\n".format("\t" * level)
        output += self.condition.getRepr(level + 1)
        output += "\n"
        for node in self.body:
            output += node.getRepr(level + 1) + "\n"
        for node in self.elifs_clause:
            output += node.getRepr(level + 1) + "\n"
        output += self.else_clause.getRepr(level + 1) + "\n"
        output += "{}</IfNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<WhileNode>\n".format("\t" * level)
        for node in self.body:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</WhileNode>".format("\t" * level)

        return output

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

    def getRepr(self, level=0):
        output = "{}<ForNode>\n".format("\t" * level)
        output += "{}<Var>\n".format("\t" * (level + 1))
        output += self.var.getRepr(level + 2)
        output += "\n"
        output += "{}</Var>\n".format("\t" * (level + 1))
        output += "{}<Container>\n".format("\t" * (level + 1))
        output += self.container.getRepr(level + 2)
        output += "\n"
        output += "{}</Container>\n".format("\t" * (level + 1))
        for node in self.body:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</ForNode>".format("\t" * level)

        return output

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class FunctionCallNode(Node):
    def __init__(self):
        super().__init__()

        self.function_name = ""
        self.args_list = []

    def getRepr(self, level=0):
        output = "{}<FunctionCallNode `{}`>\n".format("\t" * level, self.function_name)
        for node in self.args_list:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</FunctionCallNode>".format("\t" * level)

        return output

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class RetNode(Node):
    def __init__(self):
        super().__init__()

        self.ret = []

    def getRepr(self, level=0):
        output = "{}<RetNode>\n".format("\t" * level)
        for node in self.ret:
            output += node.getRepr(level + 1) + "\n"
        output += "{}</RetNode>".format("\t" * level)

        return output

    def getBytecode(self):
        pass

    def optimize(self):
        pass


class AST(Node):
    def __init__(self):
        super().__init__()
        
        self.nodes = []

    def __iter__(self):
        for node in self.nodes:
            yield node

    def addNode(self, node):
        self.nodes.append(node)

    def getRepr(self):
        output = "<Program with {} nodes>\n".format(len(self.nodes))
        for node in self:
            output += node.getRepr(1) + "\n"
        output += "</Program>"

        return output

    def getBytecode(self):
        bytecode = b""
        for node in self:
            bytecode += node.getBytecode()
        return bytecode

    def optimize(self):
        for node in self:
            node.optimize()


if __name__ == '__main__':
    raise NotImplementedError("This script isn't meant to be run directly")
