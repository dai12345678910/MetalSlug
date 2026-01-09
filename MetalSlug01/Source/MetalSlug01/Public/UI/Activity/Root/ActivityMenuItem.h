#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActivityMenuItem.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
	FOnActivityMenuClicked,
	FName,
	PageId
);

/**
 * 左侧菜单按钮
 */
UCLASS()
class METALSLUG01_API UActivityMenuItem : public UUserWidget
{
	GENERATED_BODY()

public:

	/** 页面 ID */
	UPROPERTY(BlueprintReadOnly, EditAnywhere)
	FName PageId;

	/** 点击事件 */
	UPROPERTY(BlueprintAssignable)
	FOnActivityMenuClicked OnClicked;

protected:

	virtual void NativeOnInitialized() override;

protected:

	/** 绑定按钮 */
	UPROPERTY(meta = (BindWidget))
	class UButton* ClickButton;

	UFUNCTION()
	void HandleClicked();
};
