(ns aoc2017.day3
  (:require [clojure.math.numeric-tower :as math]))

(defn perimeter-side
  "Length of a side of the j'th perimeter"
  [j]
  (+ (* 2 j) 1))

(defn manhattan-distance-to-origin
  [a b]
  (+ (math/abs a) (math/abs b)))

;; Facing E (angle 0): dx = 1, dy = 0
;; Facing N (angle 90): dx = 0, dy = 1
;; Facing W (angle 180): dx = -1, dy = 0
;; Facing S (angle 270): dx = 0, dy = -1
(def step-dirs {0 [+1 0]
                90 [0 +1]
                180 [-1 0]
                270 [0 -1]})

(defn steps-till-turn
  "How many steps remaining before the next turn?
  Depends on the angle faced and the current perimeter."
  [ang j]
  (let [side-length (perimeter-side j)]
    (cond
      (= ang 90) (- side-length 2)
      (= ang 0)  side-length
      :else (- side-length 1))))


(defn step
  "Advance one spot along the spiral grid, possibly changing direction."
  [pos]
  (let [[i x y angle perimeter steps-to-next-turn] pos
        [dx dy] (step-dirs angle)
        steps (dec steps-to-next-turn)
        turn? (= 0 steps)
        new-perimeter? (and (= 0 angle) turn?)
        ang (if turn? (rem (+ angle 90) 360) angle)
        perim (if new-perimeter? (inc perimeter) perimeter)]
    [(inc i)
     (+ x dx)
     (+ y dy)
     ang
     perim
     (if turn? (steps-till-turn ang perim) steps)]))

(def puzzle1-loc 312051)
(def puzzle1-steps (dec puzzle1-loc))

(let [[i x y] (nth (iterate step [1 0 0 0 0 1]) puzzle1-steps)] 
  (println "Puzzle 1: " (manhattan-distance-to-origin x y)))
