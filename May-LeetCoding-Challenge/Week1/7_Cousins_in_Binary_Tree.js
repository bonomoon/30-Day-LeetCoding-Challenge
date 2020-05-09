/**
 * Definition for a binary tree node.
 * function TreeNode(val, left, right) {
 *     this.val = (val===undefined ? 0 : val)
 *     this.left = (left===undefined ? null : left)
 *     this.right = (right===undefined ? null : right)
 * }
 */
/**
 * @param {TreeNode} root
 * @param {number} x
 * @param {number} y
 * @return {boolean}
 */
var isCousins = function(root, x, y) {
    let queue = [root];
    
    while(queue.length > 0) {
        let size = queue.length;
        let isXExisted = false, isYExisted = false;

        for(let i = 0; i < size; ++i) {
            let cur = queue.shift();
            
            if(cur.val === x) {
                isXExisted = true;
            }
                
            if(cur.val === y) {
                isYExisted = true;
            }
                
            if(cur.left) {
                queue.push(cur.left);
            }
            
            if(cur.right) {
                queue.push(cur.right);
            }
                
            if(cur.left && cur.right) {
                if(cur.left.val === x && cur.right.val === y) {
                    return false;
                }
                    
                if(cur.left.val === y && cur.right.val === x) {
                    return false;
                }                
            }         
        }

        if(isXExisted || isYExisted) {
            if(isXExisted && isYExisted) {
                return true;
            }
            return false;
        }
    }
    
    return false;
};