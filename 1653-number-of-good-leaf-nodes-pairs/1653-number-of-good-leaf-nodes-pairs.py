# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, val=0, left=None, right=None):
#         self.val = val
#         self.left = left
#         self.right = right
class Solution:
    def countPairs(self, root: TreeNode, distance: int) -> int:
        if not root:
            return 0
        self.good_pairs = 0
        self.postOrder(root,distance)

        return self.good_pairs

    def postOrder(self, node ,distance):
        if not node:
            return []  # Return an empty list if the node is None
        if not node.left and not node.right:
             return [1] 
        
        l_leaf_dist = self.postOrder(node.left,distance)
        r_leaf_dist = self.postOrder(node.right,distance)

        for l_leaf in l_leaf_dist:
            if l_leaf >= distance:
                continue
            for r_leaf in r_leaf_dist:
                if l_leaf + r_leaf <= distance:
                    self.good_pairs += 1

        return[1+dist for dist in l_leaf_dist + r_leaf_dist]
            
        