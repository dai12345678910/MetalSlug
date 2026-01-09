#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "ActivityConfig.generated.h"

/**
 * 单个活动页面的配置
 * 每一行 = 左侧一个按钮 + 右侧一个页面
 */
USTRUCT(BlueprintType)
struct FActivityConfig : public FTableRowBase
{
	GENERATED_BODY()

public:

	// 页面唯一 ID（用于切换）
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName PageId;

	// 左侧菜单显示文本
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FText MenuText;

	// 右侧页面 Widget（软引用，支持异步）
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSoftClassPtr<class UUserWidget> PageWidget;

	// 排序优先级（小的在前）
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int32 SortOrder = 0;
};

