from typing import List
class Solution:
	def combinationSum(self,candidates: List[int], target: int) -> List[List[int]]:

		res = []

		def make_combination(idx, comb, total):
			if total == target:
				res.append(comb[:])
				return

			if total > target or idx >= len(candidates):
				return

			comb.append(candidates[idx])
			make_combination(idx, comb, total + candidates[idx])
			comb.pop()
			make_combination(idx+1, comb, total)

			return res

		return make_combination(0, [], 0)
print(Solution().combinationSum([2,3,6,7],7))
print(Solution().combinationSum([2,3,5],8))