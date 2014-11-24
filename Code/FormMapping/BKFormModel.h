//
// Created by Bruno Wernimont on 2012
// Copyright 2012 BaseKit
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

#import <Foundation/Foundation.h>

@class BKCellMapping;
@class BKFormMapping;
@class BKFormAttributeMapping;

@interface BKFormModel : NSObject <UITableViewDataSource, UITableViewDelegate> {
    BOOL _canHideKeyBoard;
}

@property (nonatomic, retain) UITableView *tableView;
@property (nonatomic, retain) id object;
@property (nonatomic, retain) UINavigationController *navigationController;
@property (nonatomic, assign) Class selectControllerClass;

+ (id)formTableModelForTableView:(UITableView *)tableView;

+ (id)formTableModelForTableView:(UITableView *)tableView
            navigationController:(UINavigationController *)navigationController;

- (id)initWithTableView:(UITableView *)tableView
   navigationController:(UINavigationController *)navigationController;

- (void)registerMapping:(BKFormMapping *)formMapping;

- (void)loadFieldsWithObject:(id)object;

- (void)reloadRowWithAttributeMapping:(BKFormAttributeMapping *)attributeMapping;

/**
 Find the first UITextField or UITextView in the table view.
 @return Return first UITextField or UITextView.
 */
- (id)findFirstTextField;

/**
 Find all UITextField or UITextView in the table view.
 @return Return an array of UITextField and UITextView.
 */
- (NSArray *)findTextFields;

/**
 Save all attributes
 */
- (void)save;

@end
