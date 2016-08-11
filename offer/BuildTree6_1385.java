package offer;

import java.util.Scanner;

import javax.swing.RootPaneContainer;

class TreeNode {
	public TreeNode() {
		// TODO Auto-generated constructor stub
	}

	public TreeNode(int val) {
		// TODO Auto-generated constructor stub
		this.val = val;
		this.left = null;
		this.right = null;
	}

	int val;
	TreeNode left;
	TreeNode right;
}

public class BuildTree6_1385 {

	private int[] preOrder = new int[1000];
	private int[] inOrder = new int[1000];
	private int length;
	private TreeNode root;
	private boolean isTree = true;

	public void input() {
		Scanner scanner = new Scanner(System.in);
		while (scanner.hasNext()) {
			int n = scanner.nextInt();
			length = n;
			int i = 0;
			while (i < n) {
				preOrder[i] = scanner.nextInt();
				i++;
			}
			i = 0;
			while (i < n) {
				inOrder[i] = scanner.nextInt();
				i++;
			}
			construct();
			print();
			System.out.println();
			isTree = true;
			root=  null;
		}
	}

	public void construct() {
		if (length <= 0)
			return;
		root = constructTreeNode(0, length - 1, 0, length - 1);
	}

	public TreeNode constructTreeNode(int startPre, int endPre, int startIn,
			int endIn) {
		TreeNode root = new TreeNode();
		root.val = preOrder[startPre];
		root.left = null;
		root.right = null;
		if (startPre == endPre) {
			if (startIn == endIn && preOrder[startPre] == inOrder[startIn]) {
				return root;
			} else {
				isTree = false;
				return null;
			}
		}
		int loc = startIn;
		while (loc <= endIn) {
			if (inOrder[loc] == preOrder[startPre]) {
				break;
			}
			loc++;
		}
		if (loc > endIn) {
			isTree = false;
			return null;
		}
		int length = loc - startIn;
		if (loc > startIn) {
			root.left = constructTreeNode(startPre + 1, startPre + length,
					startIn, loc - 1);
		}
		if (loc < endIn) {
			root.right = constructTreeNode(startPre + length + 1, endPre,
					loc + 1, endIn);
		}
		return root;
	}

	public void postOrder(TreeNode root) {
		if (root == null) {
			return;
		}
		postOrder(root.left);
		postOrder(root.right);
		System.out.print(root.val + " ");
	}

	public void print() {
		if (isTree) {
			postOrder(root);
		} else {
			System.out.print("No");
		}
	}

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		BuildTree6_1385 s = new BuildTree6_1385();
		s.input();
		
	}

}
