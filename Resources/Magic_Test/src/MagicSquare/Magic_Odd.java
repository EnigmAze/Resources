package MagicSquare;

//�����÷���ʵ��

public class Magic_Odd {
	    //n Ϊ�÷��Ľ���
	public static int[][] magicOdd(int n) {
		//����һ��(n+2)*(n+2)�׵ķ���
		int[][] square = new int[n + 1][n + 1];
		
		int i = 0;
		int j = (n + 1) / 2;
		//�ӵ�һ�е��м��Ǹ����֣���1����ʼ��÷�
		//n�׻÷�һ����n*n�����֣���1~n*n��
		//�����׻÷���ʵ���㷨
		for (int key = 1; key <= n * n; key++) {
			if ((key % n) == 1)
				i++;
			else {  //��䵱ǰ�������Ͻ��Ǹ���
				i--;
				j++;
			} 
			
//			if (i == 0) //�ж�������������(n+2)*(n+2)�׷���ĵ�һ��
//				i = n;        //�򷵻ص�(n+2)*(n+2)�׷���ĵ����ڶ��У���n*n�׻÷������һ�У�
//			if (j > n)  //�ж����������ǳ���(n+2)*(n+2)�׷���ĵ����ڶ���
//				j = 1;       //�򷵻ص�(n+2)*(n+2)�׷���ĵڶ��У���n*n�׻÷��ĵ�һ�У�
//			square[i][j] = key;
			
			if (i == 0) {//�ж�������������(n+2)*(n+2)�׷���ĵ�һ��
				if(j==n+1){
					i=2;
					j=n;
				}else{
					i=n;
				}
			}
			else{
				if(j==n+1){
					j=1;
				}
			}
			square[i][j] = key;
			
		}
		
		
		//��(n+2)*(n+2)�׵ķ������ɸѡ���м��n*n�׻÷�
		int[][] matrix = new int[n][n];
		for (int k = 0; k < matrix.length; k++) {
			for (int l = 0; l < matrix[0].length; l++) {
				matrix[k][l] = square[k + 1][l + 1];
			}
		}
		return matrix;
		
////		int[][] matrix = new int[n][n];
////		for (int k = 0; k < matrix.length; k++) {
////			for (int l = 0; l < matrix[0].length; l++) {
////				matrix[k][l] = square[k + 1][l + 1];
////			}
////		}
//		return square;
	}
	
    //���Ժ���
	public static void main(String[] args) {
		int[][] magic = Magic_Odd.magicOdd(11); //����11�׻÷�
		for (int k = 0; k < magic.length; k++) {
			for (int l = 0; l < magic[0].length; l++) {
				System.out.print(magic[k][l] + " ");
			}
			System.out.println();
		}
	}
}
