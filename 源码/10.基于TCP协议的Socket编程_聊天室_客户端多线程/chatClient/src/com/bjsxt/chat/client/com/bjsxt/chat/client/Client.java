package com.bjsxt.chat.client;

import java.io.IOException;
import java.net.Socket;

public class Client {
	public static void main(String[] args) throws IOException {
		//(1)����Socket����
		Socket client=new Socket("localhost",10000);
		
		//�������͵��߳������
		com.bjsxt.chat.client.Send send=new com.bjsxt.chat.client.Send(client);
		//�������յ��߳������
		com.bjsxt.chat.client.Receive receive=new com.bjsxt.chat.client.Receive(client);
		//����Thread����������߳�
		new Thread(send).start();
		new Thread(receive).start();
	
	}
}
