#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActivityPageBase.generated.h"

/**
 * 所有活动页面的基类
 * 只关心生命周期
 */
UCLASS(Abstract)
class METALSLUG01_API UActivityPageBase : public UUserWidget
{
	GENERATED_BODY()

public:

	/** 页面显示时调用 */
	UFUNCTION(BlueprintNativeEvent)
	void OnPageShow();
	virtual void OnPageShow_Implementation();

	/** 页面隐藏时调用 */
	UFUNCTION(BlueprintNativeEvent)
	void OnPageHide();
	virtual void OnPageHide_Implementation();
};
