package org.intelligentjava.algos.trees;

import org.intelligentjava.algos.trees.AVLTree.AVLNode;
import org.intelligentjava.algos.trees.AbstractBinarySearchTree.Node;
import org.junit.Assert;
import org.junit.Test;

/**
 * Tests for AVL tree.
 * 
 * @author Ignas Lelys
 * @created Jun 29, 2011
 *
 */
public class AVLTreeTest extends BaseBSTTest {
    
    @Test
    public void testDelete() {
        AVLTree tree = new AVLTree();
        tree.insert(20);
        tree.insert(15);
        tree.insert(25);
        tree.insert(23);
        Assert.assertEquals(tree.size, 4);
        tree.delete(15); // root is now unbalanced rotation performed
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)23); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(tree.root.left.value, (Integer)20);
        Assert.assertEquals(tree.root.right.value, (Integer)25);
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testDeleteWithBrother() {
        AVLTree tree = new AVLTree();
        tree.insert(20);
        tree.insert(15);
        tree.insert(25);
        tree.insert(23);
        Assert.assertEquals(tree.size, 4);
        tree.delete(25); // root is now unbalanced rotation performed
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)20); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(tree.root.left.value, (Integer)15);
        Assert.assertEquals(tree.root.right.value, (Integer)23);
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testDeleteNodeNull() {
        AVLTree tree = new AVLTree();
        tree.insert(20);
        tree.insert(15);
        tree.insert(25);
        tree.insert(23);
        Assert.assertEquals(tree.size, 4);
        tree.delete(95); // root is now unbalanced rotation performed
        Assert.assertEquals(tree.size, 4);
        Assert.assertEquals(tree.root.value, (Integer)20); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 2); // new root
        Assert.assertEquals(tree.root.left.value, (Integer)15);
        Assert.assertEquals(tree.root.right.value, (Integer)25);
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testDeleteNodeRigthNotNull() {
        AVLTree tree = new AVLTree();
        tree.insert(20);
        tree.insert(15);
        tree.insert(25);
        tree.insert(23);
        tree.insert(16);
        Assert.assertEquals(tree.size, 5);
        tree.delete(20); // root is now unbalanced rotation performed
        tree.delete(23);
        tree.delete(25);
        tree.delete(16);
        Assert.assertEquals(tree.size, 1);
        Assert.assertEquals(tree.root.value, (Integer)15); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 0); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testBalanceTwoLeft() {
    	AVLTree tree = new AVLTree();
        tree.insert(20);
        tree.insert(23);
        tree.insert(19);
        tree.insert(22);
        tree.insert(18);
        tree.insert(21);
        tree.delete(20);
        Assert.assertEquals(tree.size, 5);
        Assert.assertEquals(tree.root.value, (Integer)21); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 2); // new root
        Assert.assertEquals(tree.root.left.value, (Integer)19);
        Assert.assertEquals(tree.root.right.value, (Integer)22);
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testBalanceTwoRight() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(24);
        tree.insert(55);
        tree.insert(62);
        tree.insert(18);
        tree.insert(63);
        tree.delete(48);
        Assert.assertEquals(tree.size, 5);
        Assert.assertEquals(tree.root.value, (Integer)55); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 2); // new root
        Assert.assertEquals(tree.root.left.value, (Integer)24);
        Assert.assertEquals(tree.root.right.value, (Integer)62);
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNotNodeRight() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(28);
        Assert.assertEquals(tree.size, 2);
        Assert.assertEquals(tree.root.value, (Integer)48); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNotNodeLeft() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(68);
        Assert.assertEquals(tree.size, 2);
        Assert.assertEquals(tree.root.value, (Integer)48); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNodeLeftEquals() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(28);
        tree.insert(28);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)28); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNodeLeftRigth() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(28);
        tree.insert(20);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)28); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNodeRotateLeftRigth() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(28);
        tree.insert(20);
        Assert.assertEquals(tree.root.value, (Integer)28); // new root
        //Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNodeRightEquals() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(68);
        tree.insert(68);
        tree.insert(60);
        Assert.assertEquals(tree.size, 4);
        Assert.assertEquals(tree.root.value, (Integer)68); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 2); // new root
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testContainsNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(true, tree.contains(49));
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testNotContainsNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(false, tree.contains(89));
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testGetMinimumNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(48, tree.getMinimum());
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testGetMaxNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(50, tree.getMaximum());
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testGetSuccessorNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(50, tree.getSuccessor(49));
        
        testTreeBSTProperties(tree.root);
    }
    
    @Test
    public void testGetSizeNode() {
    	AVLTree tree = new AVLTree();
        tree.insert(48);
        tree.insert(49);
        tree.insert(50);
        Assert.assertEquals(tree.size, 3);
        Assert.assertEquals(tree.root.value, (Integer)49); // new root
        Assert.assertEquals(((AVLNode)tree.root).height, 1); // new root
        Assert.assertEquals(3, tree.getSize());
        
        testTreeBSTProperties(tree.root);
    }
    
}