
#ifndef BOOST_CONTRACT_EXT_PP_ASSERTION_TRAITS_AUX_INDEX_HPP_
#define BOOST_CONTRACT_EXT_PP_ASSERTION_TRAITS_AUX_INDEX_HPP_

// WARNING: These index values must match parsing order (see assertion.hpp).

#define BOOST_CONTRACT_EXT_PP_ASSERTION_TRAITS_AUX_KEY_INDEX                0

// All indexes below start from 1 (0 taken by "key", common to all assertions).

#define BOOST_CONTRACT_EXT_PP_BOOL_ASSERTION_TRAITS_AUX_EXPR_INDEX          1

#define BOOST_CONTRACT_EXT_PP_CONST_ASSERTION_TRAITS_AUX_CAPTURES_INDEX     1
#define BOOST_CONTRACT_EXT_PP_CONST_ASSERTION_TRAITS_AUX_EXPR_INDEX         2

#define BOOST_CONTRACT_EXT_PP_IF_ASSERTION_TRAITS_AUX_COND_INDEX            1
#define BOOST_CONTRACT_EXT_PP_IF_ASSERTION_TRAITS_AUX_THENS_INDEX           2
#define BOOST_CONTRACT_EXT_PP_IF_ASSERTION_TRAITS_AUX_ELSES_INDEX           3

#define BOOST_CONTRACT_EXT_PP_RETURN_ASSERTION_TRAITS_AUX_TYPE_INDEX        1
#define BOOST_CONTRACT_EXT_PP_RETURN_ASSERTION_TRAITS_AUX_ASSIGN_INDEX      2

#define BOOST_CONTRACT_EXT_PP_OLDOF_ASSERTION_TRAITS_AUX_EXPR_INDEX         1
#define BOOST_CONTRACT_EXT_PP_OLDOF_ASSERTION_TRAITS_AUX_TYPE_INDEX         2
#define BOOST_CONTRACT_EXT_PP_OLDOF_ASSERTION_TRAITS_AUX_ASSIGN_INDEX       3

#define BOOST_CONTRACT_EXT_PP_NAMESPACE_ASSERTION_TRAITS_AUX_NEW_NAME_INDEX 1
#define BOOST_CONTRACT_EXT_PP_NAMESPACE_ASSERTION_TRAITS_AUX_NAME_INDEX     2

#define BOOST_CONTRACT_EXT_PP_USING_ASSERTION_TRAITS_AUX_TEMPLATE_PARAMS_INDEX 1
#define BOOST_CONTRACT_EXT_PP_USING_ASSERTION_TRAITS_AUX_NAMESPACE_INDEX    2
#define BOOST_CONTRACT_EXT_PP_USING_ASSERTION_TRAITS_AUX_NEW_NAME_INDEX     3
#define BOOST_CONTRACT_EXT_PP_USING_ASSERTION_TRAITS_AUX_NAME_INDEX         4

#define BOOST_CONTRACT_EXT_PP_TYPEDEF_ASSERTION_TRAITS_AUX_NAME_INDEX       1
#define BOOST_CONTRACT_EXT_PP_TYPEDEF_ASSERTION_TRAITS_AUX_NEW_NAME_INDEX   2

#endif // #include guard

