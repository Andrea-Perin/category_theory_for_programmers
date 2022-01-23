maybeToEitherUnit :: Maybe a -> Either () a
maybeToEitherUnit (Nothing) = Left ()
maybeToEitherUnit (Just x) = Right x


eitherUnitToMaybe :: Either () a -> Maybe a
eitherUnitToMaybe (Left ()) = Nothing
eitherUnitToMaybe (Right x) = Just x
