package com.bjsxt.chat.client1;

import com.bjsxt.chat.client.Receive;
import com.bjsxt.chat.client.Send;

import java.io.IOException;
import java.net.Socket;

public class Client {
	public static void main(String[] args) throws IOException {
		//(1)����Socket����
		Socket client=new Socket("localhost",10000);
		
		//�������͵��߳������
		Send send=new Send(client);
		//�������յ��߳������
		Receive receive=new Receive(client);
		//����Thread����������߳�
		new Thread(send).start();
		new Thread(receive).start();
	
	}
}
