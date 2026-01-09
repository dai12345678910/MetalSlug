#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "ActivityRoot.generated.h"

class UVerticalBox;
class UPanelWidget;
class UActivityController;
class UActivityMenuItem;

UCLASS()
class METALSLUG01_API UActivityRoot : public UUserWidget
{
	GENERATED_BODY()

protected:

	virtual void NativeOnInitialized() override;

protected:

	/** 左侧菜单容器 */
	UPROPERTY(meta = (BindWidget))
	UVerticalBox* LeftMenuBox;

	/** 右侧内容容器 */
	UPROPERTY(meta = (BindWidget))
	UPanelWidget* RightContent;

	/** 活动配置表 */
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UDataTable* ActivityConfigTable;

private:

	UPROPERTY()
	UActivityController* Controller;

	void BuildLeftMenu();
};
