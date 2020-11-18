package com.bjsxt.chat.client1;

import com.bjsxt.chat.client.Receive;
import com.bjsxt.chat.client.Send;

import java.io.IOException;
import java.net.Socket;

public class Client {
	public static void main(String[] args) throws IOException {
		//(1)创建Socket对象
		Socket client=new Socket("localhost",10000);
		
		//创建发送的线程类对象
		Send send=new Send(client);
		//创建接收的线程类对象
		Receive receive=new Receive(client);
		//创建Thread类对象并启动线程
		new Thread(send).start();
		new Thread(receive).start();
	
	}
}
