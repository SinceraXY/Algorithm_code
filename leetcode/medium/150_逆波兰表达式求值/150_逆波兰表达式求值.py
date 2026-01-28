class Solution:
    def evalRPN(self, tokens: List[str]) -> int:
        op_to_binary_fn = {
            "+": add,
            "-": sub,
            "*": mul,
            "/": lambda x, y: int(x/y),    #需要注意python中负数除法的表现与题目不一致
        }

        stack = list()
        for token in tokens:
            try:
                num = int(token)
            except ValueError:
                num2=stack.pop()
                num1=stack.pop()
                num=op_to_binary_fn[token](num1,num2)
            finally:
                stack.append(num)

        return stack[0]