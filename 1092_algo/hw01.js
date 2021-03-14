/*
data structure:

node:{
    key: int,
    height: int,
    left: node,
    rightL node
}

*/

function max_key_in_subtree(subtree){  //尋找該節點中最大的子節點
    while(subtree.right != null){
        subtree = subtree.right
    }
    return subtree;
}
function min_key_in_subtree(subtree){  //尋找該節點中最小的子節點
    while(subtree.left != null){
        subtree = subtree.left
    }
    return subtree;
}
function height(tree){  //尋找節點高度
    if(tree){
        return tree.height
    }
    return 0;
}
function L_L(tree){  //LL旋轉
    var tmp = tree.left;
    tree.left = tmp.right
    tmp.right = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_R(tree){  //RR旋轉
    var tmp = tree.right;
    tree.right = tmp.left
    tmp.left = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_L(tree){  //RL旋轉
    tree.right = L_L(tree.right)
    return R_R(tree)
}
function L_R(tree){  //LR旋轉
    tree.left = R_R(tree.left)
    return L_L(tree)
}

function delete_node(tree, key){
    if(key < tree.key){
        //欲刪除的值小於節點的值(向左子樹遞迴)
        tree = delete_node(tree.left, key)
        //在遞迴結束後進行avl平衡
        if(height(tree.right) - height(tree.left) == 2){
            if(height(tree.right.left) > height(tree.right.right)){
                tree = R_L(tree)
            }else{
                tree = R_R(tree)
            }
        }
    }else if(key > tree.key){
        //欲刪除的值大於節點的值(向右子樹遞迴)
        tree = delete_node(tree.right, key)
        //在遞迴結束後進行avl平衡
        if(height(tree.left) - height(tree.right) == 2){
            if(height(tree.left.left) > height(tree.left.right)){
                tree = L_L(tree)
            }else{
                tree = L_R(tree)
            }
        }
    }else if(key == tree.key){
        //此節點恰為要刪除的節點
        //第一次遇到時，先假設該節點左右子樹都不為空，開始進行替換
        if(tree.left && tree,right){
            if(tree.left.height > tree.right.height){
                var max_key = max_key_in_subtree(left)
                swap(max_key.key, tree.left.key)
                //目標刪除節點轉至max_key，繼續往下
                delete_node(tree.left, max_key.key)
            }else{
                var min_key = min_key_in_subtree(right)
                swap(min_key.key, tree.right.key)
                //目標刪除節點轉至min_key，繼續往下
            }
        }
        //第二次遇到或是目標恰在底層，這時他已經位於底層(必定有一邊子樹為空)
        else{
            if(tree.left){
                tree = tree.left
            }else if(tree.right){
                tree = tree.right
            }else{
                tree = null
            }
            tree.height = 0
        }
    }
    return tree
}