#include "src/builtins/builtins-array-gen.h"
#include "src/builtins/builtins-bigint-gen.h"
#include "src/builtins/builtins-collections-gen.h"
#include "src/builtins/builtins-constructor-gen.h"
#include "src/builtins/builtins-data-view-gen.h"
#include "src/builtins/builtins-iterator-gen.h"
#include "src/builtins/builtins-promise-gen.h"
#include "src/builtins/builtins-promise.h"
#include "src/builtins/builtins-proxy-gen.h"
#include "src/builtins/builtins-regexp-gen.h"
#include "src/builtins/builtins-string-gen.h"
#include "src/builtins/builtins-typed-array-gen.h"
#include "src/builtins/builtins-utils-gen.h"
#include "src/builtins/builtins.h"
#include "src/codegen/code-factory.h"
#include "src/heap/factory-inl.h"
#include "src/objects/arguments.h"
#include "src/objects/bigint.h"
#include "src/objects/elements-kind.h"
#include "src/objects/free-space.h"
#include "src/objects/js-break-iterator.h"
#include "src/objects/js-collator.h"
#include "src/objects/js-date-time-format.h"
#include "src/objects/js-display-names.h"
#include "src/objects/js-generator.h"
#include "src/objects/js-list-format.h"
#include "src/objects/js-locale.h"
#include "src/objects/js-number-format.h"
#include "src/objects/js-objects.h"
#include "src/objects/js-plural-rules.h"
#include "src/objects/js-promise.h"
#include "src/objects/js-regexp-string-iterator.h"
#include "src/objects/js-relative-time-format.h"
#include "src/objects/js-segment-iterator.h"
#include "src/objects/js-segmenter.h"
#include "src/objects/js-weak-refs.h"
#include "src/objects/objects.h"
#include "src/objects/source-text-module.h"
#include "src/objects/stack-frame-info.h"
#include "src/objects/synthetic-module.h"
#include "src/objects/template-objects.h"
#include "torque-generated/src/builtins/array-copywithin-tq-csa.h"
#include "torque-generated/src/builtins/array-every-tq-csa.h"
#include "torque-generated/src/builtins/array-filter-tq-csa.h"
#include "torque-generated/src/builtins/array-find-tq-csa.h"
#include "torque-generated/src/builtins/array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/array-isarray-tq-csa.h"
#include "torque-generated/src/builtins/array-join-tq-csa.h"
#include "torque-generated/src/builtins/array-lastindexof-tq-csa.h"
#include "torque-generated/src/builtins/array-map-tq-csa.h"
#include "torque-generated/src/builtins/array-of-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-right-tq-csa.h"
#include "torque-generated/src/builtins/array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/array-reverse-tq-csa.h"
#include "torque-generated/src/builtins/array-shift-tq-csa.h"
#include "torque-generated/src/builtins/array-slice-tq-csa.h"
#include "torque-generated/src/builtins/array-some-tq-csa.h"
#include "torque-generated/src/builtins/array-splice-tq-csa.h"
#include "torque-generated/src/builtins/array-unshift-tq-csa.h"
#include "torque-generated/src/builtins/array-tq-csa.h"
#include "torque-generated/src/builtins/base-tq-csa.h"
#include "torque-generated/src/builtins/bigint-tq-csa.h"
#include "torque-generated/src/builtins/boolean-tq-csa.h"
#include "torque-generated/src/builtins/builtins-string-tq-csa.h"
#include "torque-generated/src/builtins/collections-tq-csa.h"
#include "torque-generated/src/builtins/cast-tq-csa.h"
#include "torque-generated/src/builtins/convert-tq-csa.h"
#include "torque-generated/src/builtins/console-tq-csa.h"
#include "torque-generated/src/builtins/data-view-tq-csa.h"
#include "torque-generated/src/builtins/frames-tq-csa.h"
#include "torque-generated/src/builtins/frame-arguments-tq-csa.h"
#include "torque-generated/src/builtins/growable-fixed-array-tq-csa.h"
#include "torque-generated/src/builtins/internal-coverage-tq-csa.h"
#include "torque-generated/src/builtins/iterator-tq-csa.h"
#include "torque-generated/src/builtins/math-tq-csa.h"
#include "torque-generated/src/builtins/number-tq-csa.h"
#include "torque-generated/src/builtins/object-fromentries-tq-csa.h"
#include "torque-generated/src/builtins/object-tq-csa.h"
#include "torque-generated/src/builtins/promise-abstract-operations-tq-csa.h"
#include "torque-generated/src/builtins/promise-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-constructor-tq-csa.h"
#include "torque-generated/src/builtins/proxy-delete-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-get-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-has-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-is-extensible-tq-csa.h"
#include "torque-generated/src/builtins/proxy-prevent-extensions-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revocable-tq-csa.h"
#include "torque-generated/src/builtins/proxy-revoke-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-property-tq-csa.h"
#include "torque-generated/src/builtins/proxy-set-prototype-of-tq-csa.h"
#include "torque-generated/src/builtins/proxy-tq-csa.h"
#include "torque-generated/src/builtins/reflect-tq-csa.h"
#include "torque-generated/src/builtins/regexp-exec-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-all-tq-csa.h"
#include "torque-generated/src/builtins/regexp-match-tq-csa.h"
#include "torque-generated/src/builtins/regexp-replace-tq-csa.h"
#include "torque-generated/src/builtins/regexp-search-tq-csa.h"
#include "torque-generated/src/builtins/regexp-source-tq-csa.h"
#include "torque-generated/src/builtins/regexp-split-tq-csa.h"
#include "torque-generated/src/builtins/regexp-test-tq-csa.h"
#include "torque-generated/src/builtins/regexp-tq-csa.h"
#include "torque-generated/src/builtins/string-endswith-tq-csa.h"
#include "torque-generated/src/builtins/string-html-tq-csa.h"
#include "torque-generated/src/builtins/string-iterator-tq-csa.h"
#include "torque-generated/src/builtins/string-pad-tq-csa.h"
#include "torque-generated/src/builtins/string-repeat-tq-csa.h"
#include "torque-generated/src/builtins/string-replaceall-tq-csa.h"
#include "torque-generated/src/builtins/string-slice-tq-csa.h"
#include "torque-generated/src/builtins/string-startswith-tq-csa.h"
#include "torque-generated/src/builtins/string-substring-tq-csa.h"
#include "torque-generated/src/builtins/string-substr-tq-csa.h"
#include "torque-generated/src/builtins/symbol-tq-csa.h"
#include "torque-generated/src/builtins/torque-internal-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-createtypedarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-every-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-filter-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-find-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-findindex-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-foreach-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-from-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-of-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduce-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-reduceright-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-set-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-slice-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-some-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-sort-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-subarray-tq-csa.h"
#include "torque-generated/src/builtins/typed-array-tq-csa.h"
#include "torque-generated/src/ic/handler-configuration-tq-csa.h"
#include "torque-generated/src/objects/allocation-site-tq-csa.h"
#include "torque-generated/src/objects/api-callbacks-tq-csa.h"
#include "torque-generated/src/objects/arguments-tq-csa.h"
#include "torque-generated/src/objects/cell-tq-csa.h"
#include "torque-generated/src/objects/code-tq-csa.h"
#include "torque-generated/src/objects/contexts-tq-csa.h"
#include "torque-generated/src/objects/data-handler-tq-csa.h"
#include "torque-generated/src/objects/debug-objects-tq-csa.h"
#include "torque-generated/src/objects/descriptor-array-tq-csa.h"
#include "torque-generated/src/objects/embedder-data-array-tq-csa.h"
#include "torque-generated/src/objects/feedback-cell-tq-csa.h"
#include "torque-generated/src/objects/feedback-vector-tq-csa.h"
#include "torque-generated/src/objects/fixed-array-tq-csa.h"
#include "torque-generated/src/objects/foreign-tq-csa.h"
#include "torque-generated/src/objects/free-space-tq-csa.h"
#include "torque-generated/src/objects/heap-number-tq-csa.h"
#include "torque-generated/src/objects/heap-object-tq-csa.h"
#include "torque-generated/src/objects/intl-objects-tq-csa.h"
#include "torque-generated/src/objects/js-array-buffer-tq-csa.h"
#include "torque-generated/src/objects/js-array-tq-csa.h"
#include "torque-generated/src/objects/js-collection-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-collection-tq-csa.h"
#include "torque-generated/src/objects/js-generator-tq-csa.h"
#include "torque-generated/src/objects/js-objects-tq-csa.h"
#include "torque-generated/src/objects/js-promise-tq-csa.h"
#include "torque-generated/src/objects/js-proxy-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-string-iterator-tq-csa.h"
#include "torque-generated/src/objects/js-regexp-tq-csa.h"
#include "torque-generated/src/objects/js-weak-refs-tq-csa.h"
#include "torque-generated/src/objects/literal-objects-tq-csa.h"
#include "torque-generated/src/objects/map-tq-csa.h"
#include "torque-generated/src/objects/microtask-tq-csa.h"
#include "torque-generated/src/objects/module-tq-csa.h"
#include "torque-generated/src/objects/name-tq-csa.h"
#include "torque-generated/src/objects/oddball-tq-csa.h"
#include "torque-generated/src/objects/ordered-hash-table-tq-csa.h"
#include "torque-generated/src/objects/primitive-heap-object-tq-csa.h"
#include "torque-generated/src/objects/promise-tq-csa.h"
#include "torque-generated/src/objects/property-array-tq-csa.h"
#include "torque-generated/src/objects/property-cell-tq-csa.h"
#include "torque-generated/src/objects/prototype-info-tq-csa.h"
#include "torque-generated/src/objects/regexp-match-info-tq-csa.h"
#include "torque-generated/src/objects/script-tq-csa.h"
#include "torque-generated/src/objects/shared-function-info-tq-csa.h"
#include "torque-generated/src/objects/source-text-module-tq-csa.h"
#include "torque-generated/src/objects/stack-frame-info-tq-csa.h"
#include "torque-generated/src/objects/string-tq-csa.h"
#include "torque-generated/src/objects/struct-tq-csa.h"
#include "torque-generated/src/objects/synthetic-module-tq-csa.h"
#include "torque-generated/src/objects/template-objects-tq-csa.h"
#include "torque-generated/src/objects/template-tq-csa.h"
#include "torque-generated/src/wasm/wasm-objects-tq-csa.h"
#include "torque-generated/test/torque/test-torque-tq-csa.h"
#include "torque-generated/third_party/v8/builtins/array-sort-tq-csa.h"

namespace v8 {
namespace internal {

TF_BUILTIN(CreateHTML, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<String> parameter2 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  TNode<String> parameter3 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<2>()));
  USE(parameter3);
  TNode<String> parameter4 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<3>()));
  USE(parameter4);
  TNode<Object> parameter5 = UncheckedCast<Object>(Parameter(Descriptor::ParameterIndex<4>()));
  USE(parameter5);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, String, String, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, String, String, Object, String, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String, String, String, Object, String, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2, parameter3, parameter4, parameter5);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    TNode<String> tmp2;
    TNode<String> tmp3;
    TNode<String> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).ToThisString(TNode<Context>{tmp0}, TNode<Object>{tmp1}, TNode<String>{tmp2});
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "<");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = StringAdd_0(state_, TNode<Context>{tmp0}, TNode<String>{tmp7}, TNode<String>{tmp3});
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = kEmptyString_0(state_);
    TNode<BoolT> tmp10;
    USE(tmp10);
    tmp10 = CodeStubAssembler(state_).TaggedNotEqual(TNode<Object>{tmp4}, TNode<HeapObject>{tmp9});
    ca_.Branch(tmp10, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp8);
  }

  if (block1.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<String> tmp13;
    TNode<String> tmp14;
    TNode<String> tmp15;
    TNode<Object> tmp16;
    TNode<String> tmp17;
    TNode<String> tmp18;
    ca_.Bind(&block1, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<String> tmp19;
    USE(tmp19);
    tmp19 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp11}, TNode<Object>{tmp16});
    TNode<String> tmp20;
    tmp20 = TORQUE_CAST(CodeStubAssembler(state_).CallRuntime(Runtime::kStringEscapeQuotes, tmp11, tmp19)); 
    USE(tmp20);
    TNode<String> tmp21;
    USE(tmp21);
    tmp21 = FromConstexpr_String_constexpr_string_0(state_, " ");
    TNode<String> tmp22;
    USE(tmp22);
    tmp22 = StringAdd_0(state_, TNode<Context>{tmp11}, TNode<String>{tmp18}, TNode<String>{tmp21});
    TNode<String> tmp23;
    USE(tmp23);
    tmp23 = StringAdd_0(state_, TNode<Context>{tmp11}, TNode<String>{tmp22}, TNode<String>{tmp15});
    TNode<String> tmp24;
    USE(tmp24);
    tmp24 = FromConstexpr_String_constexpr_string_0(state_, "=\"");
    TNode<String> tmp25;
    USE(tmp25);
    tmp25 = StringAdd_0(state_, TNode<Context>{tmp11}, TNode<String>{tmp23}, TNode<String>{tmp24});
    TNode<String> tmp26;
    USE(tmp26);
    tmp26 = StringAdd_0(state_, TNode<Context>{tmp11}, TNode<String>{tmp25}, TNode<String>{tmp20});
    TNode<String> tmp27;
    USE(tmp27);
    tmp27 = FromConstexpr_String_constexpr_string_0(state_, "\"");
    TNode<String> tmp28;
    USE(tmp28);
    tmp28 = StringAdd_0(state_, TNode<Context>{tmp11}, TNode<String>{tmp26}, TNode<String>{tmp27});
    ca_.Goto(&block2, tmp11, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp28);
  }

  if (block2.is_used()) {
    TNode<Context> tmp29;
    TNode<Object> tmp30;
    TNode<String> tmp31;
    TNode<String> tmp32;
    TNode<String> tmp33;
    TNode<Object> tmp34;
    TNode<String> tmp35;
    TNode<String> tmp36;
    ca_.Bind(&block2, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36);
    TNode<String> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_String_constexpr_string_0(state_, ">");
    TNode<String> tmp38;
    USE(tmp38);
    tmp38 = StringAdd_0(state_, TNode<Context>{tmp29}, TNode<String>{tmp36}, TNode<String>{tmp37});
    TNode<String> tmp39;
    USE(tmp39);
    tmp39 = StringAdd_0(state_, TNode<Context>{tmp29}, TNode<String>{tmp38}, TNode<String>{tmp35});
    TNode<String> tmp40;
    USE(tmp40);
    tmp40 = FromConstexpr_String_constexpr_string_0(state_, "</");
    TNode<String> tmp41;
    USE(tmp41);
    tmp41 = StringAdd_0(state_, TNode<Context>{tmp29}, TNode<String>{tmp39}, TNode<String>{tmp40});
    TNode<String> tmp42;
    USE(tmp42);
    tmp42 = StringAdd_0(state_, TNode<Context>{tmp29}, TNode<String>{tmp41}, TNode<String>{tmp32});
    TNode<String> tmp43;
    USE(tmp43);
    tmp43 = FromConstexpr_String_constexpr_string_0(state_, ">");
    TNode<String> tmp44;
    USE(tmp44);
    tmp44 = StringAdd_0(state_, TNode<Context>{tmp29}, TNode<String>{tmp42}, TNode<String>{tmp43});
    CodeStubAssembler(state_).Return(tmp44);
  }
}

TF_BUILTIN(StringPrototypeAnchor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.anchor");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "a");
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "name");
    TNode<String> tmp10;
    tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp9, tmp6));
    USE(tmp10);
    arguments.PopAndReturn(tmp10);
  }
}

TF_BUILTIN(StringPrototypeBig, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.big");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "big");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeBlink, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.blink");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "blink");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeBold, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.bold");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "b");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeFontcolor, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.fontcolor");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "font");
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "color");
    TNode<String> tmp10;
    tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp9, tmp6));
    USE(tmp10);
    arguments.PopAndReturn(tmp10);
  }
}

TF_BUILTIN(StringPrototypeFontsize, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.fontsize");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "font");
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "size");
    TNode<String> tmp10;
    tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp9, tmp6));
    USE(tmp10);
    arguments.PopAndReturn(tmp10);
  }
}

TF_BUILTIN(StringPrototypeFixed, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.fixed");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "tt");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeItalics, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.italics");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "i");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeLink, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<IntPtrT> tmp5;
    USE(tmp5);
    tmp5 = FromConstexpr_intptr_constexpr_int31_0(state_, 0);
    TNode<Object> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).GetArgumentValue(TorqueStructArguments{TNode<RawPtrT>{tmp0}, TNode<RawPtrT>{tmp1}, TNode<IntPtrT>{tmp2}}, TNode<IntPtrT>{tmp5});
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.link");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "a");
    TNode<String> tmp9;
    USE(tmp9);
    tmp9 = FromConstexpr_String_constexpr_string_0(state_, "href");
    TNode<String> tmp10;
    tmp10 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp9, tmp6));
    USE(tmp10);
    arguments.PopAndReturn(tmp10);
  }
}

TF_BUILTIN(StringPrototypeSmall, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.small");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "small");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeStrike, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.strike");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "strike");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeSub, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.sub");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "sub");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

TF_BUILTIN(StringPrototypeSup, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  Node* argc = Parameter(Descriptor::kJSActualArgumentsCount);
  TNode<IntPtrT> arguments_length(ChangeInt32ToIntPtr(argc));
  TNode<RawPtrT> arguments_frame = UncheckedCast<RawPtrT>(LoadFramePointer());
  TorqueStructArguments torque_arguments(GetFrameArguments(arguments_frame, arguments_length));
  CodeStubArguments arguments(this, torque_arguments);
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = arguments.GetReceiver();
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<RawPtrT, RawPtrT, IntPtrT, NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, torque_arguments.frame, torque_arguments.base, torque_arguments.length, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<RawPtrT> tmp0;
    TNode<RawPtrT> tmp1;
    TNode<IntPtrT> tmp2;
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3, &tmp4);
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = kEmptyString_0(state_);
    TNode<String> tmp6;
    USE(tmp6);
    tmp6 = kEmptyString_0(state_);
    TNode<String> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_String_constexpr_string_0(state_, "String.prototype.sup");
    TNode<String> tmp8;
    USE(tmp8);
    tmp8 = FromConstexpr_String_constexpr_string_0(state_, "sup");
    TNode<String> tmp9;
    tmp9 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kCreateHTML, tmp3, tmp4, tmp7, tmp8, tmp5, tmp6));
    USE(tmp9);
    arguments.PopAndReturn(tmp9);
  }
}

}  // namespace internal
}  // namespace v8

