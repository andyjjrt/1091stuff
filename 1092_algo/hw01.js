/*
data structure:

node:{
    key: int,
    height: int,
    left: node,
    rightL node
}

*/

function max_key_in_subtree(subtree){
    while(subtree.right != null){
        subtree = subtree.right
    }
    return subtree;
}
function min_key_in_subtree(subtree){
    while(subtree.left != null){
        subtree = subtree.left
    }
    return subtree;
}
function height(tree){
    if(tree){
        return reww.height
    }
    return 0;
}
function L_L(tree){
    var tmp = tree.left;
    tree.left = tmp.right
    tmp.right = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_R(tree){
    var tmp = tree.right;
    tree.right = tmp.left
    tmp.left = tree
    tree.height = max(height(tree.left), height(tree.right)) + 1
    tmp.height = max(height(tmp.left), height(tmp.right)) + 1
    return tmp
}
function R_L(tree){
    tree.right = L_L(tree.right)
    return R_R(tree)
}
function L_R(tree){
    tree.left = R_R(tree.left)
    return L_L(tree)
}


function delete_node(tree, key){
    if(key < tree.key){
        tree = delete_node(tree.left, key)
        if(height(tree.right) - height(tree.left) == 2){
            if(height(tree.right.left) > height(tree.right.right)){
                tree = R_L(tree)
            }else{
                tree = R_R(tree)
            }
        }
    }else if(key > tree.key){
        tree = delete_node(tree.right, key)
        if(height(tree.left) - height(tree.right) == 2){
            if(height(tree.left.left) > height(tree.left.right)){
                tree = L_L(tree)
            }else{
                tree = L_R(tree)
            }
        }
    }else if(key == tree.key){
        if(tree.left && tree,right){
            if(tree.left.height > tree.right.height){
                var max_key = max_key_in_subtree(left)
                swap(max_key.key, tree.left.key)
                //目標刪除節點轉至max_key
                delete_node(tree.left, max_key.key)
            }else{
                var min_key = min_key_in_subtree(right)
                swap(min_key.key, tree.right.key)
                //目標刪除節點轉至min_key
            }
        }else{
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