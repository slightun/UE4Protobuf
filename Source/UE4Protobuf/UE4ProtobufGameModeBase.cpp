// Fill out your copyright notice in the Description page of Project Settings.

#include "UE4Protobuf.h"
#include "UE4ProtobufGameModeBase.h"

#include "Proto/Test.pb.h"

AUE4ProtobufGameModeBase::AUE4ProtobufGameModeBase()
{
	SearchRequest Request;
	{
		Request.set_query("test");
		Request.set_page_number(1);
		Request.set_result_per_page(2);

		auto &attr_list = *Request.mutable_attr_list();
		attr_list[1] = 1;
		attr_list[10] = 10;
	}
	const std::string Message = Request.SerializeAsString();
	UE_LOG(LogTemp, Display, TEXT("Test protobuf, Request size[%d]."), Message.size());


	{
		SearchRequest DeRequest;
		DeRequest.ParseFromString(Message);

		UE_LOG(LogTemp, Display, TEXT("Message-> page_number = %d"), DeRequest.page_number());
		for (auto &pair : DeRequest.attr_list())
		{
			UE_LOG(LogTemp, Display, TEXT("Message-> attr_list[%d] = %d"), pair.first, pair.second);
		}
	}

}


