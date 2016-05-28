package MagicSquare;

import java.util.Scanner;

import javax.sql.rowset.FilteredRowSet;

public class MagicSquare {
	
	
	//�����÷���ʵ��:
	//¬�ಽ���������׻÷��ĺ��������������Ǵ���÷�����������ơ��÷��Ľ�����
	//��־λflag(Ϊ1��ʾ������ֱ�ӵ����������׻÷���Ϊ0��ʾSingleEven_Magic�������еĵ���)
	public static void  Odd_Magic(int array[][],int k ,int flag){
		int i=k,j=(k+1)/2,c=1;
		while (c<=k*k) {
			array[i][j]=c;
			if (c%k==0) {//��c��k�ı�����������
				i-=1;
			}
			else{//��c����k�ı�������������
				i+=1;
				j+=1;
				if (i>k) {
					i=1;
				}
				if (j>k) {
					j=1;
				}
			}
			c++;
		}
		if (flag==1) {
			outputArray(array);
		}
	}
	
	//˫ż���÷���
	//���������ܹ���4�����Ļ÷����캯�������������Ǵ���÷�����������ơ��÷��Ľ���
    public static void  DoubleEven_Magic(int array[][],int k) {
		int i=1,j,c1=1,c2=k*k;
		while (i<k) {  //��4k�׿���k*k ��4*4 �ķ��飬�����Խ��ߺͷ��Խ����ϵ�Ԫ�ر��Ϊ -1
			j=1;
			while (j<k) {
				array[i][j]=array[i+1][j+1]=array[i+2][j+2]=array[i+3][j+3]
						=array[i][j+3]=array[i+1][j+2]
						=array[i+2][j+1]=array[i+3][j]= - 1;
				j+=4;
			}
			i+=4;
		}
		
		for(i=1;i<=k;i++)
			for(j=1;j<=k;j++){
				
				//���Ϊ0�Ľ����������θ�ֵ��java ����������ʵ����ʱ������Ԫ�س�ʼ����ֵΪ0��
				if (array[i][j]==0) {
					array[i][j]=c1;
				}
				//���򣬱��Ϊ-1 �Ľ��з������θ�ֵ��
				else{
					array[i][j]=c2;
				}
				c1++;
				c2--;
			}
			outputArray(array);//����÷�
		
	}
    
    
    //��ż���÷���
  	//����������4����2�Ļ÷����캯�������������Ǵ���÷�����������ơ��÷��Ľ���
    public static void  SingleEven_Magic(int array[][],int k) {
    	int a[][]=new int[k+1][k+1];
    	int b[][]=new int [k+1][k+1];
    	int m[][]=new int [k/2+1][k/2+1];
    	int i,j;
    	
    	Odd_Magic(m, k/2, 0);
    	
    	//��k/2�����׻÷�������1��4��k�׷���M
    	for(i=1;i<=k/2;i++)
    		for(j=1;j<=k/2;j++){
    			a[2*i-1][2*j-1]=a[2*i-1][2*j]=a[2*i][2*j-1]=a[2*i][2*j]=m[i][j];
    		}
    	
    	//���췽��N
    	i=1;j=1;
    	while (i<k) {
			j=1;
			while (j<k) {
				//�ϰ벿��A�� 1230
				if (i<k/2||i==k/2&&(j==k/2+2||j==k/2-2)||i==k/2+2&&j==k/2) {
					b[i][j]=1;
					b[i][j+1]=2;
					b[i+1][j]=3;
					b[i+1][j+1]=0;
				}
				//��벿��C�� 3102
				else if(i==k/2&&j<k/2-2){
					b[i][j]=3;
					b[i][j+1]=1;
					b[i+1][j]=0;
					b[i+1][j+1]=2;
				}
				//�Ұ벿��D�� 2013
				else if(i==k/2&&j>k/2+2){
					b[i][j]=2;
					b[i][j+1]=0;
					b[i+1][j]=1;
					b[i+1][j+1]=3;
				}
				//6*6 ������������� 1203
				else if(i==k/2&&j==k/2||i==k/2+2&&(j==k/2+2||j==k/2-2)){
					b[i][j]=1;
					b[i][j+1]=2;
					b[i+1][j]=0;
					b[i+1][j+1]=3;
				}
				//�°벿��B�� 2103
				else {
					b[i][j]=2;
					b[i][j+1]=1;
					b[i+1][j]=0;
					b[i+1][j+1]=3;
				}
				j+=2;
			}
			i+=2;	
		}
    	
    	for(i=1;j<=k;i++)
    	for(j=1;j<=k;j++){
    		array[i][j]=4*a[i][j]-b[i][j];  //4*M-N �÷���ʽ
    	}
    	//outputArray(array);
    	System.out.println();
    	//���ֻ÷����ʱ�м���һ�У�
    	for(i=1;i<=k;i++)
    	for(j=1;j<=k;j++){
    	    array[i][j]=a[i][j]+(k/2)*(k/2)*b[i][j];   //M+(k/2)*(k/2)*N �÷���ʽ
    	   
    	}
    	 outputArray(array);
    }
    
    //����÷��ĺ����������Ǵ���÷������������
    public static void outputArray (int array[][]) {
		for(int row=1;row<array.length;row++){
			for (int column = 1; column < array[row].length; column++) {
				System.out.printf("%5d",array[row][column]);
			}
			System.out.println();
		}
	}
    
    
    
    //���Ժ���
    public static void  main(String args[]) {
		int a[][];
		System.out.println("������÷�������");
		Scanner input =new Scanner(System.in);
		int k=input.nextInt();
		a=new int[k+1][k+1];
		
		//����Ϊ2�Ļ÷�������
		if (k==2) {
			System.out.println("�����ڽ���Ϊ2�Ļ÷������������룡");
		}
		//�����׻÷�
		else if (k%2!=0) {
			Odd_Magic(a, k, 1);
		}
		//4k�ͻ÷���˫ż���÷���
		else if (k%4==0) {
			DoubleEven_Magic(a, k);
		}
		//4k+2�ͻ÷�����ż���÷���
		else {
			SingleEven_Magic(a, k);
		}
	}
}


