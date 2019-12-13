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

TNode<Object> RegExpPrototypeMatchAllImpl_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<NativeContext> p_nativeContext, TNode<Object> p_receiver, TNode<Object> p_string) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, JSReceiver, String, Object, BoolT, BoolT, JSReceiver, JSReceiver, Context> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, JSReceiver, String, Object, BoolT, BoolT, JSReceiver, JSReceiver, Context, JSRegExp> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, JSReceiver, String, Object, BoolT, BoolT, JSReceiver, JSRegExp, PrimitiveHeapObject, String, JSRegExp> block9(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, JSReceiver, String, Object, BoolT, BoolT, JSReceiver, JSRegExp, PrimitiveHeapObject, String, JSRegExp> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, JSReceiver, String, Object, BoolT, BoolT, JSReceiver> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, NativeContext, Object, Object, Object> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_nativeContext, p_receiver, p_string);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<NativeContext> tmp1;
    TNode<Object> tmp2;
    TNode<Object> tmp3;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2, &tmp3);
    CodeStubAssembler(state_).ThrowIfNotJSReceiver(TNode<Context>{tmp0}, TNode<Object>{tmp2}, MessageTemplate::kIncompatibleMethodReceiver, "RegExp.prototype.@@matchAll");
    TNode<JSReceiver> tmp4;
    USE(tmp4);
    tmp4 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp0}, TNode<Object>{tmp2});
    TNode<String> tmp5;
    USE(tmp5);
    tmp5 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp0}, TNode<Object>{tmp3});
    TNode<JSRegExp> tmp6;
    USE(tmp6);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp6 = Cast_FastJSRegExp_0(state_, TNode<Context>{tmp0}, TNode<HeapObject>{tmp4}, &label0);
    ca_.Goto(&block4, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, ca_.Uninitialized<Object>(), ca_.Uninitialized<BoolT>(), ca_.Uninitialized<BoolT>(), tmp4, tmp4, tmp0, tmp6);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block5, tmp0, tmp1, tmp2, tmp3, tmp4, tmp5, ca_.Uninitialized<Object>(), ca_.Uninitialized<BoolT>(), ca_.Uninitialized<BoolT>(), tmp4, tmp4, tmp0);
    }
  }

  if (block5.is_used()) {
    TNode<Context> tmp7;
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<JSReceiver> tmp11;
    TNode<String> tmp12;
    TNode<Object> tmp13;
    TNode<BoolT> tmp14;
    TNode<BoolT> tmp15;
    TNode<JSReceiver> tmp16;
    TNode<JSReceiver> tmp17;
    TNode<Context> tmp18;
    ca_.Bind(&block5, &tmp7, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12, &tmp13, &tmp14, &tmp15, &tmp16, &tmp17, &tmp18);
    TNode<JSFunction> tmp19;
    USE(tmp19);
    tmp19 = LoadRegExpFunction_0(state_, TNode<Context>{tmp7}, TNode<NativeContext>{tmp8});
    TNode<JSReceiver> tmp20;
    USE(tmp20);
    tmp20 = CodeStubAssembler(state_).SpeciesConstructor(TNode<Context>{tmp7}, TNode<Object>{tmp11}, TNode<JSReceiver>{tmp19});
    TNode<JSReceiver> tmp21;
    USE(tmp21);
    tmp21 = UnsafeCast_Constructor_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp20});
    TNode<Object> tmp22;
    USE(tmp22);
    tmp22 = FromConstexpr_JSAny_constexpr_string_0(state_, "flags");
    TNode<Object> tmp23;
    USE(tmp23);
    tmp23 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp7}, TNode<Object>{tmp11}, TNode<Object>{tmp22});
    TNode<String> tmp24;
    USE(tmp24);
    tmp24 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp7}, TNode<Object>{tmp23});
    TNode<JSReceiver> tmp25;
    USE(tmp25);
    tmp25 = CodeStubAssembler(state_).Construct(TNode<Context>{tmp7}, TNode<JSReceiver>{tmp21}, TNode<Object>{tmp11}, TNode<Object>{tmp24});
    TNode<Object> tmp26;
    USE(tmp26);
    tmp26 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp7}, TNode<Object>{tmp11});
    TNode<Number> tmp27;
    USE(tmp27);
    tmp27 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp7}, TNode<Object>{tmp26});
    TNode<JSReceiver> tmp28;
    USE(tmp28);
    tmp28 = UnsafeCast_JSReceiver_0(state_, TNode<Context>{tmp7}, TNode<Object>{tmp25});
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp7}, TNode<Object>{tmp28}, TNode<Object>{tmp27});
    TNode<String> tmp29;
    USE(tmp29);
    tmp29 = CodeStubAssembler(state_).StringConstant("g");
    TNode<Smi> tmp30;
    USE(tmp30);
    tmp30 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp31;
    tmp31 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringIndexOf, tmp7, tmp24, tmp29, tmp30));
    USE(tmp31);
    TNode<Smi> tmp32;
    USE(tmp32);
    tmp32 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    TNode<BoolT> tmp33;
    USE(tmp33);
    tmp33 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp31}, TNode<Smi>{tmp32});
    TNode<String> tmp34;
    USE(tmp34);
    tmp34 = CodeStubAssembler(state_).StringConstant("u");
    TNode<Smi> tmp35;
    USE(tmp35);
    tmp35 = FromConstexpr_Smi_constexpr_int31_0(state_, 0);
    TNode<Smi> tmp36;
    tmp36 = TORQUE_CAST(CodeStubAssembler(state_).CallBuiltin(Builtins::kStringIndexOf, tmp7, tmp24, tmp34, tmp35));
    USE(tmp36);
    TNode<Smi> tmp37;
    USE(tmp37);
    tmp37 = FromConstexpr_Smi_constexpr_int31_0(state_, -1);
    TNode<BoolT> tmp38;
    USE(tmp38);
    tmp38 = CodeStubAssembler(state_).SmiNotEqual(TNode<Smi>{tmp36}, TNode<Smi>{tmp37});
    ca_.Goto(&block2, tmp7, tmp8, tmp9, tmp10, tmp11, tmp12, tmp25, tmp33, tmp38, tmp16);
  }

  if (block4.is_used()) {
    TNode<Context> tmp39;
    TNode<NativeContext> tmp40;
    TNode<Object> tmp41;
    TNode<Object> tmp42;
    TNode<JSReceiver> tmp43;
    TNode<String> tmp44;
    TNode<Object> tmp45;
    TNode<BoolT> tmp46;
    TNode<BoolT> tmp47;
    TNode<JSReceiver> tmp48;
    TNode<JSReceiver> tmp49;
    TNode<Context> tmp50;
    TNode<JSRegExp> tmp51;
    ca_.Bind(&block4, &tmp39, &tmp40, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51);
    TNode<IntPtrT> tmp52 = ca_.IntPtrConstant(JSRegExp::kSourceOffset);
    USE(tmp52);
    TNode<PrimitiveHeapObject>tmp53 = CodeStubAssembler(state_).LoadReference<PrimitiveHeapObject>(CodeStubAssembler::Reference{tmp51, tmp52});
    TNode<String> tmp54;
    USE(tmp54);
    tmp54 = FastFlagsGetter_0(state_, TNode<Context>{tmp39}, TNode<JSRegExp>{tmp51});
    TNode<Object> tmp55;
    USE(tmp55);
    tmp55 = RegExpCreate_0(state_, TNode<Context>{tmp39}, TNode<NativeContext>{tmp40}, TNode<Object>{tmp53}, TNode<String>{tmp54});
    TNode<JSRegExp> tmp56;
    USE(tmp56);
    tmp56 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp39}, TNode<Object>{tmp55});
    TNode<JSRegExp> tmp57;
    USE(tmp57);
    tmp57 = UnsafeCast_FastJSRegExp_0(state_, TNode<Context>{tmp39}, TNode<Object>{tmp43});
    TNode<Smi> tmp58;
    USE(tmp58);
    tmp58 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp57});
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp56}, TNode<Smi>{tmp58});
    TNode<BoolT> tmp59;
    USE(tmp59);
    tmp59 = RegExpBuiltinsAssembler(state_).FastFlagGetter(TNode<JSRegExp>{tmp56}, JSRegExp::kGlobal);
    TNode<BoolT> tmp60;
    USE(tmp60);
    tmp60 = RegExpBuiltinsAssembler(state_).FastFlagGetter(TNode<JSRegExp>{tmp56}, JSRegExp::kUnicode);
    ca_.Goto(&block2, tmp39, tmp40, tmp41, tmp42, tmp43, tmp44, tmp55, tmp59, tmp60, tmp48);
  }

  if (block9.is_used()) {
    TNode<Context> tmp61;
    TNode<NativeContext> tmp62;
    TNode<Object> tmp63;
    TNode<Object> tmp64;
    TNode<JSReceiver> tmp65;
    TNode<String> tmp66;
    TNode<Object> tmp67;
    TNode<BoolT> tmp68;
    TNode<BoolT> tmp69;
    TNode<JSReceiver> tmp70;
    TNode<JSRegExp> tmp71;
    TNode<PrimitiveHeapObject> tmp72;
    TNode<String> tmp73;
    TNode<JSRegExp> tmp74;
    ca_.Bind(&block9, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69, &tmp70, &tmp71, &tmp72, &tmp73, &tmp74);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastRegExpPermissive(matcherRegExp)' failed", "src/builtins/regexp-match-all.tq", 43);
  }

  if (block8.is_used()) {
    TNode<Context> tmp75;
    TNode<NativeContext> tmp76;
    TNode<Object> tmp77;
    TNode<Object> tmp78;
    TNode<JSReceiver> tmp79;
    TNode<String> tmp80;
    TNode<Object> tmp81;
    TNode<BoolT> tmp82;
    TNode<BoolT> tmp83;
    TNode<JSReceiver> tmp84;
    TNode<JSRegExp> tmp85;
    TNode<PrimitiveHeapObject> tmp86;
    TNode<String> tmp87;
    TNode<JSRegExp> tmp88;
    ca_.Bind(&block8, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79, &tmp80, &tmp81, &tmp82, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88);
  }

  if (block2.is_used()) {
    TNode<Context> tmp89;
    TNode<NativeContext> tmp90;
    TNode<Object> tmp91;
    TNode<Object> tmp92;
    TNode<JSReceiver> tmp93;
    TNode<String> tmp94;
    TNode<Object> tmp95;
    TNode<BoolT> tmp96;
    TNode<BoolT> tmp97;
    TNode<JSReceiver> tmp98;
    ca_.Bind(&block2, &tmp89, &tmp90, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    TNode<Object> tmp99;
    USE(tmp99);
    tmp99 = RegExpMatchAllAssembler(state_).CreateRegExpStringIterator(TNode<NativeContext>{tmp90}, TNode<Object>{tmp95}, TNode<String>{tmp94}, TNode<BoolT>{tmp96}, TNode<BoolT>{tmp97});
    ca_.Goto(&block10, tmp89, tmp90, tmp91, tmp92, tmp99);
  }

    TNode<Context> tmp100;
    TNode<NativeContext> tmp101;
    TNode<Object> tmp102;
    TNode<Object> tmp103;
    TNode<Object> tmp104;
    ca_.Bind(&block10, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104);
  return TNode<Object>{tmp104};
}

TF_BUILTIN(RegExpPrototypeMatchAll, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  TNode<Object> parameter2 = UncheckedCast<Object>(Parameter(Descriptor::kString));
  USE(parameter2);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1, parameter2);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    TNode<Object> tmp2;
    ca_.Bind(&block0, &tmp0, &tmp1, &tmp2);
    TNode<Object> tmp3;
    USE(tmp3);
    tmp3 = RegExpPrototypeMatchAllImpl_0(state_, TNode<Context>{tmp0}, TNode<NativeContext>{tmp0}, TNode<Object>{tmp1}, TNode<Object>{tmp2});
    CodeStubAssembler(state_).Return(tmp3);
  }
}

TNode<BoolT> HasDoneFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_flags);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsSetSmi(TNode<Smi>{tmp0}, 1 << JSRegExpStringIterator::kDoneBit);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BoolT>{tmp3};
}

TNode<BoolT> HasGlobalFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_flags);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsSetSmi(TNode<Smi>{tmp0}, 1 << JSRegExpStringIterator::kGlobalBit);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BoolT>{tmp3};
}

TNode<BoolT> HasUnicodeFlag_0(compiler::CodeAssemblerState* state_, TNode<Smi> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Smi, BoolT> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_flags);

  if (block0.is_used()) {
    TNode<Smi> tmp0;
    ca_.Bind(&block0, &tmp0);
    TNode<BoolT> tmp1;
    USE(tmp1);
    tmp1 = CodeStubAssembler(state_).IsSetSmi(TNode<Smi>{tmp0}, 1 << JSRegExpStringIterator::kUnicodeBit);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<Smi> tmp2;
    TNode<BoolT> tmp3;
    ca_.Bind(&block2, &tmp2, &tmp3);
  return TNode<BoolT>{tmp3};
}

void SetDoneFlag_0(compiler::CodeAssemblerState* state_, TNode<JSRegExpStringIterator> p_iterator, TNode<Smi> p_flags) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<JSRegExpStringIterator, Smi> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<JSRegExpStringIterator, Smi> block2(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_iterator, p_flags);

  if (block0.is_used()) {
    TNode<JSRegExpStringIterator> tmp0;
    TNode<Smi> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<Smi> tmp2;
    USE(tmp2);
    tmp2 = FromConstexpr_Smi_constexpr_int31_0(state_, 1 << JSRegExpStringIterator::kDoneBit);
    TNode<Smi> tmp3;
    USE(tmp3);
    tmp3 = CodeStubAssembler(state_).SmiOr(TNode<Smi>{tmp1}, TNode<Smi>{tmp2});
    TNode<IntPtrT> tmp4 = ca_.IntPtrConstant(JSRegExpStringIterator::kFlagsOffset);
    USE(tmp4);
    CodeStubAssembler(state_).StoreReference(CodeStubAssembler::Reference{tmp0, tmp4}, tmp3);
    ca_.Goto(&block2, tmp0, tmp1);
  }

    TNode<JSRegExpStringIterator> tmp5;
    TNode<Smi> tmp6;
    ca_.Bind(&block2, &tmp5, &tmp6);
}

TF_BUILTIN(RegExpStringIteratorPrototypeNext, CodeStubAssembler) {
  compiler::CodeAssemblerState* state_ = state();  compiler::CodeAssembler ca_(state());
  TNode<NativeContext> parameter0 = UncheckedCast<NativeContext>(Parameter(Descriptor::kContext));
  USE(parameter0);
  TNode<Object> parameter1 = UncheckedCast<Object>(Parameter(Descriptor::kReceiver));
USE(parameter1);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, Object, NativeContext, JSRegExpStringIterator> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi> block8(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block11(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSRegExp, Number, JSRegExp, String, Number, NativeContext> block15(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSRegExp, Number, JSRegExp, String, Number, NativeContext, RegExpMatchInfo> block14(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block12(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block16(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block17(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block13(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block18(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block19(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block23(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block22(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block24(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block30(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, FixedArray, IntPtrT, IntPtrT, IntPtrT, HeapObject, IntPtrT, IntPtrT, IntPtrT, IntPtrT> block31(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, String> block36(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, String> block35(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, String, JSRegExp> block37(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, JSArray, FixedArray, String, JSRegExp> block38(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block25(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block42(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block41(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, Object, String> block43(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT, Object, String> block44(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator, Smi, JSReceiver, String, Object, BoolT> block10(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<NativeContext, Object, JSRegExpStringIterator> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, parameter0, parameter1);

  if (block0.is_used()) {
    TNode<NativeContext> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExpStringIterator> tmp2;
    USE(tmp2);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp2 = Cast_JSRegExpStringIterator_1(state_, TNode<Context>{tmp0}, TNode<Object>{tmp1}, &label0);
    ca_.Goto(&block3, tmp0, tmp1, tmp1, tmp0, tmp2);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block4, tmp0, tmp1, tmp1, tmp0);
    }
  }

  if (block4.is_used()) {
    TNode<NativeContext> tmp3;
    TNode<Object> tmp4;
    TNode<Object> tmp5;
    TNode<NativeContext> tmp6;
    ca_.Bind(&block4, &tmp3, &tmp4, &tmp5, &tmp6);
    TNode<Object> tmp7;
    USE(tmp7);
    tmp7 = FromConstexpr_Object_constexpr_string_0(state_, "%RegExpStringIterator%.prototype.next");
    CodeStubAssembler(state_).ThrowTypeError(TNode<Context>{tmp3}, MessageTemplate::kIncompatibleMethodReceiver, TNode<Object>{tmp7}, TNode<Object>{tmp4});
  }

  if (block3.is_used()) {
    TNode<NativeContext> tmp8;
    TNode<Object> tmp9;
    TNode<Object> tmp10;
    TNode<NativeContext> tmp11;
    TNode<JSRegExpStringIterator> tmp12;
    ca_.Bind(&block3, &tmp8, &tmp9, &tmp10, &tmp11, &tmp12);
    TNode<IntPtrT> tmp13 = ca_.IntPtrConstant(JSRegExpStringIterator::kFlagsOffset);
    USE(tmp13);
    TNode<Smi>tmp14 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp12, tmp13});
    TNode<BoolT> tmp15;
    USE(tmp15);
    tmp15 = HasDoneFlag_0(state_, TNode<Smi>{tmp14});
    ca_.Branch(tmp15, &block7, &block8, tmp8, tmp9, tmp12, tmp14);
  }

  if (block7.is_used()) {
    TNode<NativeContext> tmp16;
    TNode<Object> tmp17;
    TNode<JSRegExpStringIterator> tmp18;
    TNode<Smi> tmp19;
    ca_.Bind(&block7, &tmp16, &tmp17, &tmp18, &tmp19);
    ca_.Goto(&block6, tmp16, tmp17, tmp18);
  }

  if (block8.is_used()) {
    TNode<NativeContext> tmp20;
    TNode<Object> tmp21;
    TNode<JSRegExpStringIterator> tmp22;
    TNode<Smi> tmp23;
    ca_.Bind(&block8, &tmp20, &tmp21, &tmp22, &tmp23);
    TNode<IntPtrT> tmp24 = ca_.IntPtrConstant(JSRegExpStringIterator::kIteratingRegExpOffset);
    USE(tmp24);
    TNode<JSReceiver>tmp25 = CodeStubAssembler(state_).LoadReference<JSReceiver>(CodeStubAssembler::Reference{tmp22, tmp24});
    TNode<IntPtrT> tmp26 = ca_.IntPtrConstant(JSRegExpStringIterator::kIteratedStringOffset);
    USE(tmp26);
    TNode<String>tmp27 = CodeStubAssembler(state_).LoadReference<String>(CodeStubAssembler::Reference{tmp22, tmp26});
    TNode<BoolT> tmp28;
    USE(tmp28);
    tmp28 = FromConstexpr_bool_constexpr_bool_0(state_, false);
    TNode<BoolT> tmp29;
    USE(tmp29);
    tmp29 = IsFastRegExpPermissive_0(state_, TNode<Context>{tmp20}, TNode<HeapObject>{tmp25});
    ca_.Branch(tmp29, &block11, &block12, tmp20, tmp21, tmp22, tmp23, tmp25, tmp27, ca_.Uninitialized<Object>(), tmp28);
  }

  if (block11.is_used()) {
    TNode<NativeContext> tmp30;
    TNode<Object> tmp31;
    TNode<JSRegExpStringIterator> tmp32;
    TNode<Smi> tmp33;
    TNode<JSReceiver> tmp34;
    TNode<String> tmp35;
    TNode<Object> tmp36;
    TNode<BoolT> tmp37;
    ca_.Bind(&block11, &tmp30, &tmp31, &tmp32, &tmp33, &tmp34, &tmp35, &tmp36, &tmp37);
    TNode<JSRegExp> tmp38;
    USE(tmp38);
    tmp38 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp30}, TNode<Object>{tmp34});
    TNode<Number> tmp39;
    USE(tmp39);
    tmp39 = LoadLastIndexAsLength_0(state_, TNode<Context>{tmp30}, TNode<JSRegExp>{tmp38}, true);
    TNode<RegExpMatchInfo> tmp40;
    USE(tmp40);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp40 = RegExpPrototypeExecBodyWithoutResultFast_1(state_, TNode<Context>{tmp30}, TNode<JSRegExp>{tmp38}, TNode<String>{tmp35}, TNode<Number>{tmp39}, &label0);
    ca_.Goto(&block14, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp38, tmp35, tmp39, tmp30, tmp40);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block15, tmp30, tmp31, tmp32, tmp33, tmp34, tmp35, tmp36, tmp37, tmp38, tmp39, tmp38, tmp35, tmp39, tmp30);
    }
  }

  if (block15.is_used()) {
    TNode<NativeContext> tmp41;
    TNode<Object> tmp42;
    TNode<JSRegExpStringIterator> tmp43;
    TNode<Smi> tmp44;
    TNode<JSReceiver> tmp45;
    TNode<String> tmp46;
    TNode<Object> tmp47;
    TNode<BoolT> tmp48;
    TNode<JSRegExp> tmp49;
    TNode<Number> tmp50;
    TNode<JSRegExp> tmp51;
    TNode<String> tmp52;
    TNode<Number> tmp53;
    TNode<NativeContext> tmp54;
    ca_.Bind(&block15, &tmp41, &tmp42, &tmp43, &tmp44, &tmp45, &tmp46, &tmp47, &tmp48, &tmp49, &tmp50, &tmp51, &tmp52, &tmp53, &tmp54);
    ca_.Goto(&block10, tmp41, tmp42, tmp43, tmp44, tmp45, tmp46, tmp47, tmp48);
  }

  if (block14.is_used()) {
    TNode<NativeContext> tmp55;
    TNode<Object> tmp56;
    TNode<JSRegExpStringIterator> tmp57;
    TNode<Smi> tmp58;
    TNode<JSReceiver> tmp59;
    TNode<String> tmp60;
    TNode<Object> tmp61;
    TNode<BoolT> tmp62;
    TNode<JSRegExp> tmp63;
    TNode<Number> tmp64;
    TNode<JSRegExp> tmp65;
    TNode<String> tmp66;
    TNode<Number> tmp67;
    TNode<NativeContext> tmp68;
    TNode<RegExpMatchInfo> tmp69;
    ca_.Bind(&block14, &tmp55, &tmp56, &tmp57, &tmp58, &tmp59, &tmp60, &tmp61, &tmp62, &tmp63, &tmp64, &tmp65, &tmp66, &tmp67, &tmp68, &tmp69);
    TNode<JSArray> tmp70;
    USE(tmp70);
    tmp70 = RegExpBuiltinsAssembler(state_).ConstructNewResultFromMatchInfo(TNode<Context>{tmp55}, TNode<JSRegExp>{tmp63}, TNode<RegExpMatchInfo>{tmp69}, TNode<String>{tmp60}, TNode<Number>{tmp64});
    TNode<BoolT> tmp71;
    USE(tmp71);
    tmp71 = FromConstexpr_bool_constexpr_bool_0(state_, true);
    ca_.Goto(&block13, tmp55, tmp56, tmp57, tmp58, tmp59, tmp60, tmp70, tmp71);
  }

  if (block12.is_used()) {
    TNode<NativeContext> tmp72;
    TNode<Object> tmp73;
    TNode<JSRegExpStringIterator> tmp74;
    TNode<Smi> tmp75;
    TNode<JSReceiver> tmp76;
    TNode<String> tmp77;
    TNode<Object> tmp78;
    TNode<BoolT> tmp79;
    ca_.Bind(&block12, &tmp72, &tmp73, &tmp74, &tmp75, &tmp76, &tmp77, &tmp78, &tmp79);
    TNode<Object> tmp80;
    USE(tmp80);
    tmp80 = RegExpExec_0(state_, TNode<Context>{tmp72}, TNode<JSReceiver>{tmp76}, TNode<String>{tmp77});
    TNode<Oddball> tmp81;
    USE(tmp81);
    tmp81 = Null_0(state_);
    TNode<BoolT> tmp82;
    USE(tmp82);
    tmp82 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp80}, TNode<HeapObject>{tmp81});
    ca_.Branch(tmp82, &block16, &block17, tmp72, tmp73, tmp74, tmp75, tmp76, tmp77, tmp80, tmp79);
  }

  if (block16.is_used()) {
    TNode<NativeContext> tmp83;
    TNode<Object> tmp84;
    TNode<JSRegExpStringIterator> tmp85;
    TNode<Smi> tmp86;
    TNode<JSReceiver> tmp87;
    TNode<String> tmp88;
    TNode<Object> tmp89;
    TNode<BoolT> tmp90;
    ca_.Bind(&block16, &tmp83, &tmp84, &tmp85, &tmp86, &tmp87, &tmp88, &tmp89, &tmp90);
    ca_.Goto(&block10, tmp83, tmp84, tmp85, tmp86, tmp87, tmp88, tmp89, tmp90);
  }

  if (block17.is_used()) {
    TNode<NativeContext> tmp91;
    TNode<Object> tmp92;
    TNode<JSRegExpStringIterator> tmp93;
    TNode<Smi> tmp94;
    TNode<JSReceiver> tmp95;
    TNode<String> tmp96;
    TNode<Object> tmp97;
    TNode<BoolT> tmp98;
    ca_.Bind(&block17, &tmp91, &tmp92, &tmp93, &tmp94, &tmp95, &tmp96, &tmp97, &tmp98);
    ca_.Goto(&block13, tmp91, tmp92, tmp93, tmp94, tmp95, tmp96, tmp97, tmp98);
  }

  if (block13.is_used()) {
    TNode<NativeContext> tmp99;
    TNode<Object> tmp100;
    TNode<JSRegExpStringIterator> tmp101;
    TNode<Smi> tmp102;
    TNode<JSReceiver> tmp103;
    TNode<String> tmp104;
    TNode<Object> tmp105;
    TNode<BoolT> tmp106;
    ca_.Bind(&block13, &tmp99, &tmp100, &tmp101, &tmp102, &tmp103, &tmp104, &tmp105, &tmp106);
    TNode<BoolT> tmp107;
    USE(tmp107);
    tmp107 = HasGlobalFlag_0(state_, TNode<Smi>{tmp102});
    TNode<BoolT> tmp108;
    USE(tmp108);
    tmp108 = CodeStubAssembler(state_).Word32BinaryNot(TNode<BoolT>{tmp107});
    ca_.Branch(tmp108, &block18, &block19, tmp99, tmp100, tmp101, tmp102, tmp103, tmp104, tmp105, tmp106);
  }

  if (block18.is_used()) {
    TNode<NativeContext> tmp109;
    TNode<Object> tmp110;
    TNode<JSRegExpStringIterator> tmp111;
    TNode<Smi> tmp112;
    TNode<JSReceiver> tmp113;
    TNode<String> tmp114;
    TNode<Object> tmp115;
    TNode<BoolT> tmp116;
    ca_.Bind(&block18, &tmp109, &tmp110, &tmp111, &tmp112, &tmp113, &tmp114, &tmp115, &tmp116);
    SetDoneFlag_0(state_, TNode<JSRegExpStringIterator>{tmp111}, TNode<Smi>{tmp112});
    TNode<Object> tmp117;
    USE(tmp117);
    tmp117 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp109}, TNode<Object>{tmp115});
    TNode<Oddball> tmp118;
    USE(tmp118);
    tmp118 = False_0(state_);
    TNode<JSObject> tmp119;
    USE(tmp119);
    tmp119 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{tmp109}, TNode<Object>{tmp117}, TNode<Oddball>{tmp118});
    CodeStubAssembler(state_).Return(tmp119);
  }

  if (block19.is_used()) {
    TNode<NativeContext> tmp120;
    TNode<Object> tmp121;
    TNode<JSRegExpStringIterator> tmp122;
    TNode<Smi> tmp123;
    TNode<JSReceiver> tmp124;
    TNode<String> tmp125;
    TNode<Object> tmp126;
    TNode<BoolT> tmp127;
    ca_.Bind(&block19, &tmp120, &tmp121, &tmp122, &tmp123, &tmp124, &tmp125, &tmp126, &tmp127);
    ca_.Branch(tmp127, &block24, &block25, tmp120, tmp121, tmp122, tmp123, tmp124, tmp125, tmp126, tmp127);
  }

  if (block23.is_used()) {
    TNode<NativeContext> tmp128;
    TNode<Object> tmp129;
    TNode<JSRegExpStringIterator> tmp130;
    TNode<Smi> tmp131;
    TNode<JSReceiver> tmp132;
    TNode<String> tmp133;
    TNode<Object> tmp134;
    TNode<BoolT> tmp135;
    ca_.Bind(&block23, &tmp128, &tmp129, &tmp130, &tmp131, &tmp132, &tmp133, &tmp134, &tmp135);
    CodeStubAssembler(state_).FailAssert("Torque assert 'HasGlobalFlag(flags)' failed", "src/builtins/regexp-match-all.tq", 189);
  }

  if (block22.is_used()) {
    TNode<NativeContext> tmp136;
    TNode<Object> tmp137;
    TNode<JSRegExpStringIterator> tmp138;
    TNode<Smi> tmp139;
    TNode<JSReceiver> tmp140;
    TNode<String> tmp141;
    TNode<Object> tmp142;
    TNode<BoolT> tmp143;
    ca_.Bind(&block22, &tmp136, &tmp137, &tmp138, &tmp139, &tmp140, &tmp141, &tmp142, &tmp143);
  }

  if (block24.is_used()) {
    TNode<NativeContext> tmp144;
    TNode<Object> tmp145;
    TNode<JSRegExpStringIterator> tmp146;
    TNode<Smi> tmp147;
    TNode<JSReceiver> tmp148;
    TNode<String> tmp149;
    TNode<Object> tmp150;
    TNode<BoolT> tmp151;
    ca_.Bind(&block24, &tmp144, &tmp145, &tmp146, &tmp147, &tmp148, &tmp149, &tmp150, &tmp151);
    TNode<JSArray> tmp152;
    USE(tmp152);
    tmp152 = UnsafeCast_JSRegExpResult_0(state_, TNode<Context>{tmp144}, TNode<Object>{tmp150});
    TNode<IntPtrT> tmp153 = ca_.IntPtrConstant(JSObject::kElementsOffset);
    USE(tmp153);
    TNode<FixedArrayBase>tmp154 = CodeStubAssembler(state_).LoadReference<FixedArrayBase>(CodeStubAssembler::Reference{tmp152, tmp153});
    TNode<FixedArray> tmp155;
    USE(tmp155);
    tmp155 = UnsafeCast_FixedArray_0(state_, TNode<Context>{tmp144}, TNode<Object>{tmp154});
    TNode<IntPtrT> tmp156 = ca_.IntPtrConstant(FixedArray::kObjectsOffset);
    USE(tmp156);
    TNode<IntPtrT> tmp157 = ca_.IntPtrConstant(FixedArrayBase::kLengthOffset);
    USE(tmp157);
    TNode<Smi>tmp158 = CodeStubAssembler(state_).LoadReference<Smi>(CodeStubAssembler::Reference{tmp155, tmp157});
    TNode<IntPtrT> tmp159;
    USE(tmp159);
    tmp159 = Convert_intptr_Smi_0(state_, TNode<Smi>{tmp158});
    TNode<IntPtrT> tmp160;
    USE(tmp160);
    tmp160 = Convert_intptr_constexpr_int31_0(state_, 0);
    TNode<UintPtrT> tmp161;
    USE(tmp161);
    tmp161 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp160});
    TNode<UintPtrT> tmp162;
    USE(tmp162);
    tmp162 = Convert_uintptr_intptr_0(state_, TNode<IntPtrT>{tmp159});
    TNode<BoolT> tmp163;
    USE(tmp163);
    tmp163 = CodeStubAssembler(state_).UintPtrLessThan(TNode<UintPtrT>{tmp161}, TNode<UintPtrT>{tmp162});
    ca_.Branch(tmp163, &block30, &block31, tmp144, tmp145, tmp146, tmp147, tmp148, tmp149, tmp150, tmp151, tmp152, tmp155, tmp155, tmp156, tmp159, tmp160, tmp155, tmp156, tmp159, tmp160, tmp160);
  }

  if (block30.is_used()) {
    TNode<NativeContext> tmp164;
    TNode<Object> tmp165;
    TNode<JSRegExpStringIterator> tmp166;
    TNode<Smi> tmp167;
    TNode<JSReceiver> tmp168;
    TNode<String> tmp169;
    TNode<Object> tmp170;
    TNode<BoolT> tmp171;
    TNode<JSArray> tmp172;
    TNode<FixedArray> tmp173;
    TNode<FixedArray> tmp174;
    TNode<IntPtrT> tmp175;
    TNode<IntPtrT> tmp176;
    TNode<IntPtrT> tmp177;
    TNode<HeapObject> tmp178;
    TNode<IntPtrT> tmp179;
    TNode<IntPtrT> tmp180;
    TNode<IntPtrT> tmp181;
    TNode<IntPtrT> tmp182;
    ca_.Bind(&block30, &tmp164, &tmp165, &tmp166, &tmp167, &tmp168, &tmp169, &tmp170, &tmp171, &tmp172, &tmp173, &tmp174, &tmp175, &tmp176, &tmp177, &tmp178, &tmp179, &tmp180, &tmp181, &tmp182);
    TNode<IntPtrT> tmp183;
    USE(tmp183);
    tmp183 = FromConstexpr_intptr_constexpr_int31_0(state_, kTaggedSize);
    TNode<IntPtrT> tmp184;
    USE(tmp184);
    tmp184 = CodeStubAssembler(state_).IntPtrMul(TNode<IntPtrT>{tmp182}, TNode<IntPtrT>{tmp183});
    TNode<IntPtrT> tmp185;
    USE(tmp185);
    tmp185 = CodeStubAssembler(state_).IntPtrAdd(TNode<IntPtrT>{tmp179}, TNode<IntPtrT>{tmp184});
    TNode<HeapObject> tmp186;
    USE(tmp186);
    TNode<IntPtrT> tmp187;
    USE(tmp187);
    std::tie(tmp186, tmp187) = UnsafeNewReference_Object_0(state_, TNode<HeapObject>{tmp178}, TNode<IntPtrT>{tmp185}).Flatten();
    TNode<Object>tmp188 = CodeStubAssembler(state_).LoadReference<Object>(CodeStubAssembler::Reference{tmp186, tmp187});
    TNode<String> tmp189;
    USE(tmp189);
    tmp189 = UnsafeCast_String_0(state_, TNode<Context>{tmp164}, TNode<Object>{tmp188});
    TNode<JSRegExp> tmp190;
    USE(tmp190);
    tmp190 = UnsafeCast_JSRegExp_0(state_, TNode<Context>{tmp164}, TNode<Object>{tmp168});
    TNode<String> tmp191;
    USE(tmp191);
    tmp191 = kEmptyString_0(state_);
    TNode<BoolT> tmp192;
    USE(tmp192);
    tmp192 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp189}, TNode<HeapObject>{tmp191});
    ca_.Branch(tmp192, &block37, &block38, tmp164, tmp165, tmp166, tmp167, tmp168, tmp169, tmp170, tmp171, tmp172, tmp173, tmp189, tmp190);
  }

  if (block31.is_used()) {
    TNode<NativeContext> tmp193;
    TNode<Object> tmp194;
    TNode<JSRegExpStringIterator> tmp195;
    TNode<Smi> tmp196;
    TNode<JSReceiver> tmp197;
    TNode<String> tmp198;
    TNode<Object> tmp199;
    TNode<BoolT> tmp200;
    TNode<JSArray> tmp201;
    TNode<FixedArray> tmp202;
    TNode<FixedArray> tmp203;
    TNode<IntPtrT> tmp204;
    TNode<IntPtrT> tmp205;
    TNode<IntPtrT> tmp206;
    TNode<HeapObject> tmp207;
    TNode<IntPtrT> tmp208;
    TNode<IntPtrT> tmp209;
    TNode<IntPtrT> tmp210;
    TNode<IntPtrT> tmp211;
    ca_.Bind(&block31, &tmp193, &tmp194, &tmp195, &tmp196, &tmp197, &tmp198, &tmp199, &tmp200, &tmp201, &tmp202, &tmp203, &tmp204, &tmp205, &tmp206, &tmp207, &tmp208, &tmp209, &tmp210, &tmp211);
    CodeStubAssembler(state_).Unreachable();
  }

  if (block36.is_used()) {
    TNode<NativeContext> tmp212;
    TNode<Object> tmp213;
    TNode<JSRegExpStringIterator> tmp214;
    TNode<Smi> tmp215;
    TNode<JSReceiver> tmp216;
    TNode<String> tmp217;
    TNode<Object> tmp218;
    TNode<BoolT> tmp219;
    TNode<JSArray> tmp220;
    TNode<FixedArray> tmp221;
    TNode<String> tmp222;
    ca_.Bind(&block36, &tmp212, &tmp213, &tmp214, &tmp215, &tmp216, &tmp217, &tmp218, &tmp219, &tmp220, &tmp221, &tmp222);
    CodeStubAssembler(state_).FailAssert("Torque assert 'IsFastRegExpPermissive(iteratingRegExp)' failed", "src/builtins/regexp-match-all.tq", 198);
  }

  if (block35.is_used()) {
    TNode<NativeContext> tmp223;
    TNode<Object> tmp224;
    TNode<JSRegExpStringIterator> tmp225;
    TNode<Smi> tmp226;
    TNode<JSReceiver> tmp227;
    TNode<String> tmp228;
    TNode<Object> tmp229;
    TNode<BoolT> tmp230;
    TNode<JSArray> tmp231;
    TNode<FixedArray> tmp232;
    TNode<String> tmp233;
    ca_.Bind(&block35, &tmp223, &tmp224, &tmp225, &tmp226, &tmp227, &tmp228, &tmp229, &tmp230, &tmp231, &tmp232, &tmp233);
  }

  if (block37.is_used()) {
    TNode<NativeContext> tmp234;
    TNode<Object> tmp235;
    TNode<JSRegExpStringIterator> tmp236;
    TNode<Smi> tmp237;
    TNode<JSReceiver> tmp238;
    TNode<String> tmp239;
    TNode<Object> tmp240;
    TNode<BoolT> tmp241;
    TNode<JSArray> tmp242;
    TNode<FixedArray> tmp243;
    TNode<String> tmp244;
    TNode<JSRegExp> tmp245;
    ca_.Bind(&block37, &tmp234, &tmp235, &tmp236, &tmp237, &tmp238, &tmp239, &tmp240, &tmp241, &tmp242, &tmp243, &tmp244, &tmp245);
    TNode<Smi> tmp246;
    USE(tmp246);
    tmp246 = RegExpBuiltinsAssembler(state_).FastLoadLastIndex(TNode<JSRegExp>{tmp245});
    TNode<BoolT> tmp247;
    USE(tmp247);
    tmp247 = HasUnicodeFlag_0(state_, TNode<Smi>{tmp237});
    TNode<Smi> tmp248;
    USE(tmp248);
    tmp248 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexFast(TNode<String>{tmp239}, TNode<Smi>{tmp246}, TNode<BoolT>{tmp247});
    RegExpBuiltinsAssembler(state_).FastStoreLastIndex(TNode<JSRegExp>{tmp245}, TNode<Smi>{tmp248});
    ca_.Goto(&block38, tmp234, tmp235, tmp236, tmp237, tmp238, tmp239, tmp240, tmp241, tmp242, tmp243, tmp244, tmp245);
  }

  if (block38.is_used()) {
    TNode<NativeContext> tmp249;
    TNode<Object> tmp250;
    TNode<JSRegExpStringIterator> tmp251;
    TNode<Smi> tmp252;
    TNode<JSReceiver> tmp253;
    TNode<String> tmp254;
    TNode<Object> tmp255;
    TNode<BoolT> tmp256;
    TNode<JSArray> tmp257;
    TNode<FixedArray> tmp258;
    TNode<String> tmp259;
    TNode<JSRegExp> tmp260;
    ca_.Bind(&block38, &tmp249, &tmp250, &tmp251, &tmp252, &tmp253, &tmp254, &tmp255, &tmp256, &tmp257, &tmp258, &tmp259, &tmp260);
    TNode<Oddball> tmp261;
    USE(tmp261);
    tmp261 = False_0(state_);
    TNode<JSObject> tmp262;
    USE(tmp262);
    tmp262 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{tmp249}, TNode<Object>{tmp257}, TNode<Oddball>{tmp261});
    CodeStubAssembler(state_).Return(tmp262);
  }

  if (block25.is_used()) {
    TNode<NativeContext> tmp263;
    TNode<Object> tmp264;
    TNode<JSRegExpStringIterator> tmp265;
    TNode<Smi> tmp266;
    TNode<JSReceiver> tmp267;
    TNode<String> tmp268;
    TNode<Object> tmp269;
    TNode<BoolT> tmp270;
    ca_.Bind(&block25, &tmp263, &tmp264, &tmp265, &tmp266, &tmp267, &tmp268, &tmp269, &tmp270);
    TNode<Object> tmp271;
    USE(tmp271);
    tmp271 = UnsafeCast_JSAny_0(state_, TNode<Context>{tmp263}, TNode<Object>{tmp269});
    TNode<Smi> tmp272;
    USE(tmp272);
    tmp272 = CodeStubAssembler(state_).SmiConstant(0);
    TNode<Object> tmp273;
    USE(tmp273);
    tmp273 = CodeStubAssembler(state_).GetProperty(TNode<Context>{tmp263}, TNode<Object>{tmp271}, TNode<Object>{tmp272});
    TNode<String> tmp274;
    USE(tmp274);
    tmp274 = CodeStubAssembler(state_).ToString_Inline(TNode<Context>{tmp263}, TNode<Object>{tmp273});
    TNode<String> tmp275;
    USE(tmp275);
    tmp275 = kEmptyString_0(state_);
    TNode<BoolT> tmp276;
    USE(tmp276);
    tmp276 = CodeStubAssembler(state_).TaggedEqual(TNode<Object>{tmp274}, TNode<HeapObject>{tmp275});
    ca_.Branch(tmp276, &block43, &block44, tmp263, tmp264, tmp265, tmp266, tmp267, tmp268, tmp269, tmp270, tmp271, tmp274);
  }

  if (block42.is_used()) {
    TNode<NativeContext> tmp277;
    TNode<Object> tmp278;
    TNode<JSRegExpStringIterator> tmp279;
    TNode<Smi> tmp280;
    TNode<JSReceiver> tmp281;
    TNode<String> tmp282;
    TNode<Object> tmp283;
    TNode<BoolT> tmp284;
    ca_.Bind(&block42, &tmp277, &tmp278, &tmp279, &tmp280, &tmp281, &tmp282, &tmp283, &tmp284);
    CodeStubAssembler(state_).FailAssert("Torque assert '!isFastRegExp' failed", "src/builtins/regexp-match-all.tq", 216);
  }

  if (block41.is_used()) {
    TNode<NativeContext> tmp285;
    TNode<Object> tmp286;
    TNode<JSRegExpStringIterator> tmp287;
    TNode<Smi> tmp288;
    TNode<JSReceiver> tmp289;
    TNode<String> tmp290;
    TNode<Object> tmp291;
    TNode<BoolT> tmp292;
    ca_.Bind(&block41, &tmp285, &tmp286, &tmp287, &tmp288, &tmp289, &tmp290, &tmp291, &tmp292);
  }

  if (block43.is_used()) {
    TNode<NativeContext> tmp293;
    TNode<Object> tmp294;
    TNode<JSRegExpStringIterator> tmp295;
    TNode<Smi> tmp296;
    TNode<JSReceiver> tmp297;
    TNode<String> tmp298;
    TNode<Object> tmp299;
    TNode<BoolT> tmp300;
    TNode<Object> tmp301;
    TNode<String> tmp302;
    ca_.Bind(&block43, &tmp293, &tmp294, &tmp295, &tmp296, &tmp297, &tmp298, &tmp299, &tmp300, &tmp301, &tmp302);
    TNode<Object> tmp303;
    USE(tmp303);
    tmp303 = RegExpBuiltinsAssembler(state_).SlowLoadLastIndex(TNode<Context>{tmp293}, TNode<Object>{tmp297});
    TNode<Number> tmp304;
    USE(tmp304);
    tmp304 = CodeStubAssembler(state_).ToLength_Inline(TNode<Context>{tmp293}, TNode<Object>{tmp303});
    TNode<BoolT> tmp305;
    USE(tmp305);
    tmp305 = HasUnicodeFlag_0(state_, TNode<Smi>{tmp296});
    TNode<Smi> tmp306;
    USE(tmp306);
    tmp306 = RegExpBuiltinsAssembler(state_).AdvanceStringIndexSlow(TNode<String>{tmp298}, TNode<Number>{tmp304}, TNode<BoolT>{tmp305});
    RegExpBuiltinsAssembler(state_).SlowStoreLastIndex(TNode<Context>{tmp293}, TNode<Object>{tmp297}, TNode<Object>{tmp306});
    ca_.Goto(&block44, tmp293, tmp294, tmp295, tmp296, tmp297, tmp298, tmp299, tmp300, tmp301, tmp302);
  }

  if (block44.is_used()) {
    TNode<NativeContext> tmp307;
    TNode<Object> tmp308;
    TNode<JSRegExpStringIterator> tmp309;
    TNode<Smi> tmp310;
    TNode<JSReceiver> tmp311;
    TNode<String> tmp312;
    TNode<Object> tmp313;
    TNode<BoolT> tmp314;
    TNode<Object> tmp315;
    TNode<String> tmp316;
    ca_.Bind(&block44, &tmp307, &tmp308, &tmp309, &tmp310, &tmp311, &tmp312, &tmp313, &tmp314, &tmp315, &tmp316);
    TNode<Oddball> tmp317;
    USE(tmp317);
    tmp317 = False_0(state_);
    TNode<JSObject> tmp318;
    USE(tmp318);
    tmp318 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{tmp307}, TNode<Object>{tmp315}, TNode<Oddball>{tmp317});
    CodeStubAssembler(state_).Return(tmp318);
  }

  if (block10.is_used()) {
    TNode<NativeContext> tmp319;
    TNode<Object> tmp320;
    TNode<JSRegExpStringIterator> tmp321;
    TNode<Smi> tmp322;
    TNode<JSReceiver> tmp323;
    TNode<String> tmp324;
    TNode<Object> tmp325;
    TNode<BoolT> tmp326;
    ca_.Bind(&block10, &tmp319, &tmp320, &tmp321, &tmp322, &tmp323, &tmp324, &tmp325, &tmp326);
    SetDoneFlag_0(state_, TNode<JSRegExpStringIterator>{tmp321}, TNode<Smi>{tmp322});
    ca_.Goto(&block6, tmp319, tmp320, tmp321);
  }

  if (block6.is_used()) {
    TNode<NativeContext> tmp327;
    TNode<Object> tmp328;
    TNode<JSRegExpStringIterator> tmp329;
    ca_.Bind(&block6, &tmp327, &tmp328, &tmp329);
    TNode<Oddball> tmp330;
    USE(tmp330);
    tmp330 = Undefined_0(state_);
    TNode<Oddball> tmp331;
    USE(tmp331);
    tmp331 = True_0(state_);
    TNode<JSObject> tmp332;
    USE(tmp332);
    tmp332 = CodeStubAssembler(state_).AllocateJSIteratorResult(TNode<Context>{tmp327}, TNode<Object>{tmp330}, TNode<Oddball>{tmp331});
    CodeStubAssembler(state_).Return(tmp332);
  }
}

TNode<JSRegExp> UnsafeCast_JSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSRegExp> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSRegExp> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSRegExp>{tmp9};
}

TNode<JSRegExp> UnsafeCast_FastJSRegExp_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSRegExp> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSRegExp> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSRegExp> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSRegExp>{tmp9};
}

TNode<JSRegExpStringIterator> Cast_JSRegExpStringIterator_1(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o, compiler::CodeAssemblerLabel* label_CastError) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, Object, HeapObject> block3(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, HeapObject, JSRegExpStringIterator> block5(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<> block1(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSRegExpStringIterator> block7(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
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
    TNode<JSRegExpStringIterator> tmp10;
    USE(tmp10);
    compiler::CodeAssemblerLabel label0(&ca_);
    tmp10 = Cast_JSRegExpStringIterator_0(state_, TNode<HeapObject>{tmp9}, &label0);
    ca_.Goto(&block5, tmp6, tmp7, tmp9, tmp10);
    if (label0.is_used()) {
      ca_.Bind(&label0);
      ca_.Goto(&block6, tmp6, tmp7, tmp9);
    }
  }

  if (block6.is_used()) {
    TNode<Context> tmp11;
    TNode<Object> tmp12;
    TNode<HeapObject> tmp13;
    ca_.Bind(&block6, &tmp11, &tmp12, &tmp13);
    ca_.Goto(&block1);
  }

  if (block5.is_used()) {
    TNode<Context> tmp14;
    TNode<Object> tmp15;
    TNode<HeapObject> tmp16;
    TNode<JSRegExpStringIterator> tmp17;
    ca_.Bind(&block5, &tmp14, &tmp15, &tmp16, &tmp17);
    ca_.Goto(&block7, tmp14, tmp15, tmp17);
  }

  if (block1.is_used()) {
    ca_.Bind(&block1);
    ca_.Goto(label_CastError);
  }

    TNode<Context> tmp18;
    TNode<Object> tmp19;
    TNode<JSRegExpStringIterator> tmp20;
    ca_.Bind(&block7, &tmp18, &tmp19, &tmp20);
  return TNode<JSRegExpStringIterator>{tmp20};
}

TNode<JSArray> UnsafeCast_JSRegExpResult_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, JSArray> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<JSArray> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<JSArray> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<JSArray>{tmp9};
}

TNode<String> UnsafeCast_String_0(compiler::CodeAssemblerState* state_, TNode<Context> p_context, TNode<Object> p_o) {
  compiler::CodeAssembler ca_(state_);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block0(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block5(&ca_, compiler::CodeAssemblerLabel::kDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object> block4(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
  compiler::CodeAssemblerParameterizedLabel<Context, Object, String> block6(&ca_, compiler::CodeAssemblerLabel::kNonDeferred);
    ca_.Goto(&block0, p_context, p_o);

  if (block0.is_used()) {
    TNode<Context> tmp0;
    TNode<Object> tmp1;
    ca_.Bind(&block0, &tmp0, &tmp1);
    TNode<String> tmp2;
    USE(tmp2);
    tmp2 = TORQUE_CAST(TNode<Object>{tmp1});
    ca_.Goto(&block6, tmp0, tmp1, tmp2);
  }

  if (block5.is_used()) {
    TNode<Context> tmp3;
    TNode<Object> tmp4;
    ca_.Bind(&block5, &tmp3, &tmp4);
    CodeStubAssembler(state_).FailAssert("Torque assert 'Is<A>(o)' failed", "src/builtins/base.tq", 914);
  }

  if (block4.is_used()) {
    TNode<Context> tmp5;
    TNode<Object> tmp6;
    ca_.Bind(&block4, &tmp5, &tmp6);
  }

    TNode<Context> tmp7;
    TNode<Object> tmp8;
    TNode<String> tmp9;
    ca_.Bind(&block6, &tmp7, &tmp8, &tmp9);
  return TNode<String>{tmp9};
}

}  // namespace internal
}  // namespace v8

