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

TNode<Object> RegExpPrototypeSearchBodyFast_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSRegExp> p_regexp, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Smi, JSRegExp, String, Context> block9(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Smi, JSRegExp, String, Context, RegExpMatchInfo> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Smi, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Smi, RegExpMatchInfo, RegExpMatchInfo, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String, Object> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp1});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp1}, TNode<Smi>{tmp4});
    TNode<JSRegExp> tmp5;
    USE(tmp5);
    tmp5 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<RegExpMatchInfo> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = RegExpPrototypeExecBodyWithoutResultFast_0(state_, TNode<Context>{tmp0}, TNode<JSRegExp>{tmp5}, TNode<String>{tmp2}, &label0);
    ca_.Goto(&block8, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block9, tmp0, tmp1, tmp2, tmp3, tmp5, tmp2, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<JSRegExp> tmp8;
    TNode<String> tmp9;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastRegExpPermissive(regexp)' failed", "src/builtins/regexp-search.tq", 12);
  }

  if (block4.is_used()) {
    TNode<Context> tmp10;
    TNode<JSRegExp> tmp11;
    TNode<String> tmp12;
    ca_.Bind(&block4, &tmp10, &tmp11, &tmp12);
  }

  if (block9.is_used()) {
    TNode<Context> tmp13;
    TNode<JSRegExp> tmp14;
    TNode<String> tmp15;
    TNode<Smi> tmp16;
    TNode<JSRegExp> tmp17;
    TNode<String> tmp18;
    TNode<Context> tmp19;
    ca_.Bind(&block9, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp14}, TNode<Smi>{tmp16});
    TNode<Smi> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).SmiConstant(-1);
    ca_.Goto(&block1, tmp13, tmp14, tmp15, tmp20);
  }

  if (block8.is_used()) {
    TNode<Context> tmp21;
    TNode<JSRegExp> tmp22;
    TNode<String> tmp23;
    TNode<Smi> tmp24;
    TNode<JSRegExp> tmp25;
    TNode<String> tmp26;
    TNode<Context> tmp27;
    TNode<RegExpMatchInfo> tmp28;
    ca_.Bind(&block8, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27, &tmp28);
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp22}, TNode<Smi>{tmp24});
    TNode<IntPtrT> tmp29 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp29);
    TNode<IntPtrT> tmp30 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp30);
    TNode<Smi>tmp31 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp28, tmp30});
    TNode<IntPtrT> tmp32;
    USE(tmp32);
    tmp32 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp31});
    TNode<IntPtrT> tmp33;
    USE(tmp33);
    tmp33 = Convert_intptr_constexpr_int31_0(state_, RegExpMatchInfo::kFirstCaptureIndex);
    TNode<UintPtrT> tmp34;
    USE(tmp34);
    tmp34 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp33});
    TNode<UintPtrT> tmp35;
    USE(tmp35);
    tmp35 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp32});
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp34}, TNode<UintPtrT>{tmp35});
    ca_.Branch(tmp36, &block14, &block15, tmp21, tmp22, tmp23, tmp24, tmp28, tmp28, tmp29, tmp32, tmp33, tmp28, tmp29, tmp32, tmp33, tmp33);
  }

  if (block14.is_used()) {
    TNode<Context> tmp37;
    TNode<JSRegExp> tmp38;
    TNode<String> tmp39;
    TNode<Smi> tmp40;
    TNode<RegExpMatchInfo> tmp41;
    TNode<RegExpMatchInfo> tmp42;
    TNode<IntPtrT> tmp43;
    TNode<IntPtrT> tmp44;
    TNode<IntPtrT> tmp45;
    TNode<HeapObject> tmp46;
    TNode<IntPtrT> tmp47;
    TNode<IntPtrT> tmp48;
    TNode<IntPtrT> tmp49;
    TNode<IntPtrT> tmp50;
    ca_.Bind(&block14, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50);
    TNode<IntPtrT> tmp51;
    USE(tmp51);
    tmp51 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp52;
    USE(tmp52);
    tmp52 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp50}, TNode<IntPtrT>{tmp51});
    TNode<IntPtrT> tmp53;
    USE(tmp53);
    tmp53 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp47}, TNode<IntPtrT>{tmp52});
    TNode<HeapObject> tmp54;
    USE(tmp54);
    TNode<IntPtrT> tmp55;
    USE(tmp55);
    std::tie(tmp54, tmp55) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp46}, TNode<IntPtrT>{tmp53}).Flatten();
    TNode<Object>tmp56 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp54, tmp55});
    TNode<Smi> tmp57;
    USE(tmp57);
    tmp57 = UnsafeCast_Smi_0(state_, TNode<Context>{tmp37}, TNode<Object>{tmp56});
    ca_.Goto(&block1, tmp37, tmp38, tmp39, tmp57);
  }

  if (block15.is_used()) {
    TNode<Context> tmp58;
    TNode<JSRegExp> tmp59;
    TNode<String> tmp60;
    TNode<Smi> tmp61;
    TNode<RegExpMatchInfo> tmp62;
    TNode<RegExpMatchInfo> tmp63;
    TNode<IntPtrT> tmp64;
    TNode<IntPtrT> tmp65;
    TNode<IntPtrT> tmp66;
    TNode<HeapObject> tmp67;
    TNode<IntPtrT> tmp68;
    TNode<IntPtrT> tmp69;
    TNode<IntPtrT> tmp70;
    TNode<IntPtrT> tmp71;
    ca_.Bind(&block15, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block1.is_used()) {
    TNode<Context> tmp72;
    TNode<JSRegExp> tmp73;
    TNode<String> tmp74;
    TNode<Object> tmp75;
    ca_.Bind(&block1, &tmp72, &tmp73, &tmp74, &tmp75);
    ca_.Goto(&block17, tmp72, tmp73, tmp74, tmp75);
  }

    TNode<Context> tmp76;
    TNode<JSRegExp> tmp77;
    TNode<String> tmp78;
    TNode<Object> tmp79;
    ca_.Bind(&block17, &tmp76, &tmp77, &tmp78, &tmp79);
  return TNode<Object>{tmp79};
}

TNode<BoolT> IsRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<HeapObject> p_execResult) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, HeapObject, Context> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, HeapObject, BoolT> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_execResult);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<HeapObject> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    compiler::CodeAssemblerLabel label0(&ca_);
    compiler::CodeAssemblerLabel label1(&ca_);
    RegExpBuiltinsAssembler(state_).BranchIfRegExpResult(TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0, &label1);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp0, tmp1, tmp1, tmp0);
    }
    if (label1.is_used()) {
      ca_.Bind(&label1);
      ca_.Goto(&block7, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp2;
    TNode<HeapObject> tmp3;
    TNode<HeapObject> tmp4;
    TNode<Context> tmp5;
    ca_.Bind(&block6, &tmp2, &tmp3, &tmp4, &tmp5);
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block1, tmp2, tmp3, tmp6);
  }

  if (block7.is_used()) {
    TNode<Context> tmp7;
    TNode<HeapObject> tmp8;
    TNode<HeapObject> tmp9;
    TNode<Context> tmp10;
    ca_.Bind(&block7, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<BoolT> tmp11;
    USE(tmp11);
    tmp11 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    ca_.Goto(&block1, tmp7, tmp8, tmp11);
  }

  if (block1.is_used()) {
    TNode<Context> tmp12;
    TNode<HeapObject> tmp13;
    TNode<BoolT> tmp14;
    ca_.Bind(&block1, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block8, tmp12, tmp13, tmp14);
  }

    TNode<Context> tmp15;
    TNode<HeapObject> tmp16;
    TNode<BoolT> tmp17;
    ca_.Bind(&block8, &tmp15, &tmp16, &tmp17);
  return TNode<BoolT>{tmp17};
}

TNode<Object> RegExpPrototypeSearchBodySlow_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<JSReceiver> p_regexp, TNode<String> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object, Object, Context> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object, Smi, Object, Object, Object, Context, JSArray> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, JSReceiver, String, Object> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_regexp, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSReceiver> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<Smi> tmp4;
    USE(tmp4);
    tmp4 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = SameValue_0(state_, TNode<Object>{tmp3}, TNode<Object>{tmp4});
    TNode<BoolT> tmp6;
    USE(tmp6);
    tmp6 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp5});
    ca_.Branch(tmp6, &block2, &block3, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block2.is_used()) {
    TNode<Context> tmp7;
    TNode<JSReceiver> tmp8;
    TNode<String> tmp9;
    TNode<Object> tmp10;
    TNode<Smi> tmp11;
    ca_.Bind(&block2, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11);
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp7}, TNode<Object>{tmp8}, TNode<Object>{tmp11});
    ca_.Goto(&block3, tmp7, tmp8, tmp9, tmp10, tmp11);
  }

  if (block3.is_used()) {
    TNode<Context> tmp12;
    TNode<JSReceiver> tmp13;
    TNode<String> tmp14;
    TNode<Object> tmp15;
    TNode<Smi> tmp16;
    ca_.Bind(&block3, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16);
    TNode<Object> tmp17;
    USE(tmp17);
    tmp17 = RegExpExec_0(state_, TNode<Context>{tmp12}, TNode<JSReceiver>{tmp13}, TNode<String>{tmp14});
    TNode<Object> tmp18;
    USE(tmp18);
    tmp18 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp12}, TNode<Object>{tmp13});
    TNode<BoolT> tmp19;
    USE(tmp19);
    tmp19 = SameValue_0(state_, TNode<Object>{tmp18}, TNode<Object>{tmp15});
    TNode<BoolT> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp19});
    ca_.Branch(tmp20, &block4, &block5, tmp12, tmp13, tmp14, tmp15, tmp16, tmp17, tmp18);
  }

  if (block4.is_used()) {
    TNode<Context> tmp21;
    TNode<JSReceiver> tmp22;
    TNode<String> tmp23;
    TNode<Object> tmp24;
    TNode<Smi> tmp25;
    TNode<Object> tmp26;
    TNode<Object> tmp27;
    ca_.Bind(&block4, &tmp21, &tmp22, &tmp23, &tmp24, &tmp25, &tmp26, &tmp27);
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp21}, TNode<Object>{tmp22}, TNode<Object>{tmp24});
    ca_.Goto(&block5, tmp21, tmp22, tmp23, tmp24, tmp25, tmp26, tmp27);
  }

  if (block5.is_used()) {
    TNode<Context> tmp28;
    TNode<JSReceiver> tmp29;
    TNode<String> tmp30;
    TNode<Object> tmp31;
    TNode<Smi> tmp32;
    TNode<Object> tmp33;
    TNode<Object> tmp34;
    ca_.Bind(&block5, &tmp28, &tmp29, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34);
    TNode<Oddball> tmp35;
    USE(tmp35);
    tmp35 = Null_0(state_);
    TNode<BoolT> tmp36;
    USE(tmp36);
    tmp36 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp33}, TNode<HeapObject>{tmp35});
    ca_.Branch(tmp36, &block6, &block7, tmp28, tmp29, tmp30, tmp31, tmp32, tmp33, tmp34);
  }

  if (block6.is_used()) {
    TNode<Context> tmp37;
    TNode<JSReceiver> tmp38;
    TNode<String> tmp39;
    TNode<Object> tmp40;
    TNode<Smi> tmp41;
    TNode<Object> tmp42;
    TNode<Object> tmp43;
    ca_.Bind(&block6, &tmp37, &tmp38, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43);
    TNode<Smi> tmp44;
    USE(tmp44);
    tmp44 = CodeStubAssembler(state_).SmiConstant(-1);
    ca_.Goto(&block1, tmp37, tmp38, tmp39, tmp44);
  }

  if (block7.is_used()) {
    TNode<Context> tmp45;
    TNode<JSReceiver> tmp46;
    TNode<String> tmp47;
    TNode<Object> tmp48;
    TNode<Smi> tmp49;
    TNode<Object> tmp50;
    TNode<Object> tmp51;
    ca_.Bind(&block7, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<JSArray> tmp52;
    USE(tmp52);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp52 = Cast_JSRegExpResult_1(state_, TNode<Context>{tmp45}, TNode<Object>{tmp50}, &label0);
    ca_.Goto(&block10, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp50, tmp45, tmp52);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block11, tmp45, tmp46, tmp47, tmp48, tmp49, tmp50, tmp51, tmp50, tmp45);
    }
  }

  if (block11.is_used()) {
    TNode<Context> tmp53;
    TNode<JSReceiver> tmp54;
    TNode<String> tmp55;
    TNode<Object> tmp56;
    TNode<Smi> tmp57;
    TNode<Object> tmp58;
    TNode<Object> tmp59;
    TNode<Object> tmp60;
    TNode<Context> tmp61;
    ca_.Bind(&block11, &tmp53, &tmp54, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61);
    TNode<Object> tmp62;
    USE(tmp62);
    tmp62 = FromConstexpr_JSAny_constexpr_string_0(state_, "index");
    TNode<Object> tmp63;
    USE(tmp63);
    tmp63 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp53}, TNode<Object>{tmp58}, TNode<Object>{tmp62});
    ca_.Goto(&block1, tmp53, tmp54, tmp55, tmp63);
  }

  if (block10.is_used()) {
    TNode<Context> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<String> tmp66;
    TNode<Object> tmp67;
    TNode<Smi> tmp68;
    TNode<Object> tmp69;
    TNode<Object> tmp70;
    TNode<Object> tmp71;
    TNode<Context> tmp72;
    TNode<JSArray> tmp73;
    ca_.Bind(&block10, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73);
    TNode<IntPtrT> tmp74 = ca_.IntPtrConstant(JSRegExpResult::kIndexOffset);
    USE(tmp74);
    TNode<Object>tmp75 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp73, tmp74});
    ca_.Goto(&block1, tmp64, tmp65, tmp66, tmp75);
  }

  if (block1.is_used()) {
    TNode<Context> tmp76;
    TNode<JSReceiver> tmp77;
    TNode<String> tmp78;
    TNode<Object> tmp79;
    ca_.Bind(&block1, &tmp76, &tmp77, &tmp78, &tmp79);
    ca_.Goto(&block12, tmp76, tmp77, tmp78, tmp79);
  }

    TNode<Context> tmp80;
    TNode<JSReceiver> tmp81;
    TNode<String> tmp82;
    TNode<Object> tmp83;
    ca_.Bind(&block12, &tmp80, &tmp81, &tmp82, &tmp83);
  return TNode<Object>{tmp83};
}

TF_BUILTIN(RegExpSearchFast, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<Context> parameter0 = UncheckedCast<Context>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<JSRegExp> parameter1 = UncheckedCast<JSRegExp>(Parameter(Descriptor::ParameterIndex<0>()));
  USE(parameter1);
  TNode<String> parameter2 = UncheckedCast<String>(Parameter(Descriptor::ParameterIndex<1>()));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<Context, JSRegExp, String> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<JSRegExp> tmp1;
    TNode<String> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = RegExpPrototypeSearchBodyFast_0(state_, TNode<Context>{tmp0}, TNode<JSRegExp>{tmp1}, TNode<String>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TF_BUILTIN(RegExpPrototypeSearch, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kString));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSReceiver, String> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, JSReceiver, String> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{tmp0}, TNode<Object>{tmp1}, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@search");
    TNode<JSReceiver> tmp3;
    USE(tmp3);
    tmp3 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1});
    TNode<String> tmp4;
    USE(tmp4);
    tmp4 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<BoolT> tmp5;
    USE(tmp5);
    tmp5 = IsFastRegExpPermissive_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp3});
    ca_.Branch(tmp5, &block1, &block2, tmp0, tmp1, tmp2, tmp3, tmp4);
  }

  if (block1.is_used()) {
    TNode<NativeContext> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<JSReceiver> tmp9;
    TNode<String> tmp10;
    ca_.Bind(&block1, &tmp6, &tmp7, &tmp8, &tmp9, &tmp10);
    TNode<JSRegExp> tmp11;
    USE(tmp11);
    tmp11 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp6}, TNode<Object>{tmp9});
    TNode<Object> tmp12;
    tmp12 = CodeStubAssembler(state_).CallBuiltin(Builtins::kRegExpSearchFast, tmp6, tmp11, tmp10);
    USE(tmp12);
    CodeStubAssembler(state_).Return(tmp12);
  }

  if (block2.is_used()) {
    TNode<NativeContext> tmp13;
    TNode<Object> tmp14;
    TNode<Object> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<String> tmp17;
    ca_.Bind(&block2, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17);
    TNode<Object> tmp18;
    USE(tmp18);
    tmp18 = RegExpPrototypeSearchBodySlow_0(state_, TNode<Context>{tmp13}, TNode<JSReceiver>{tmp16}, TNode<String>{tmp17});
    CodeStubAssembler(state_).Return(tmp18);
  }
}

TNode<JSArray> Cast_JSRegExpResult_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, Context, JSArray> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArray> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<HeapObject> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = CodeStubAssembler(state_).TaggedToHeapObject(TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1);
    }
  }

  if (block4.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5);
    ca_.Goto(&block1);
  }

  if (block3.is_used()) {
    TNode<Context> tmp6;
    TNode<Object> tmp7;
    TNode<Object> tmp8;
    TNode<HeapObject> tmp9;
    ca_.Bind(&block3, &tmp6, &tmp7, &tmp8, &tmp9);
    TNode<JSArray> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSRegExpResult_0(state_, TNode<Context>{tmp6}, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp6, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9, tmp6);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    TNode<Context> tmp14;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13, &tmp14);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp15;
    TNode<Object> tmp16;
    TNode<HeapObject> tmp17;
    TNode<Context> tmp18;
    TNode<JSArray> tmp19;
    ca_.Bind(&block5, &tmp15, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block7, tmp15, tmp16, tmp19);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp20;
    TNode<Object> tmp21;
    TNode<JSArray> tmp22;
    ca_.Bind(&block7, &tmp20, &tmp21, &tmp22);
  return TNode<JSArray>{tmp22};
}

}  // namespace internal
}  // namespace v8

