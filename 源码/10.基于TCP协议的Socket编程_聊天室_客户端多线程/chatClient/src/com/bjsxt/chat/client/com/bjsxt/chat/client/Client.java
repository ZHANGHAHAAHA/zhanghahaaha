package com.bjsxt.chat.client;

import java.io.IOException;
import java.net.Socket;

public class Client {
	public static void main(String[] args) throws IOException {
		//(1)创建Socket对象
		Socket client=new Socket("localhost",10000);
		
		//创建发送的线程类对象
		com.bjsxt.chat.client.Send send=new com.bjsxt.chat.client.Send(client);
		//创建接收的线程类对象
		com.bjsxt.chat.client.Receive receive=new com.bjsxt.chat.client.Receive(client);
		//创建Thread类对象并启动线程
		new Thread(send).start();
		new Thread(receive).start();
	
	}
}
